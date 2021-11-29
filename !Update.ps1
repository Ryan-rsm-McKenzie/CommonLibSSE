$ErrorActionPreference = "Stop"

function Walk-Files {
    param (
        [Parameter(ValueFromPipeline)]
        [string]$a_parent = $PSScriptRoot,

        [Parameter()]
        [string[]]$a_directory = @('include', 'src', 'test'),

        [Parameter()]
        [string[]]$a_extension = '*.c,*.cpp,*.cxx,*.h,*.hpp,*.hxx'
    )
    
    process {
        Push-Location $PSScriptRoot # out of source invocation sucks
        $_generated = ""

        try {
            foreach ($directory in $a_directory) {
                Write-Host "`t<$a_parent/$directory>"
                Get-ChildItem "$a_parent/$directory" -Recurse -File -Include $a_extention -Exclude Version.h -ErrorAction SilentlyContinue | Resolve-Path -Relative | ForEach-Object {
                    Write-Host "`t`t<$_>"
                    $file = $_.SubString(2).Insert(0, "`n`t") -replace '\\', '/' # \\/\//\/\\/\\\/\\/?!?
                    $_generated = $_generated + $file
                }
            }
        } finally {
            Pop-Location
        }

        return $_generated
    }
}

# args
$a_mode = $args[0] ## COPY SOURCEGEN DISTRIBUTE
$a_version = $args[1]
$a_path = $args[2]
$a_project = $args[3]
$a_isAE = $args[4]

$GameBase
$MO2Base

# project path
$Folder = $PSScriptRoot | Split-Path -Leaf

# operation
Write-Host "`n`t<$Folder> [$a_mode] BEGIN`n"
if ($a_mode -eq 'COPY') { # post build copy event
    
    if ($a_isAE -eq 'TRUE') {
        $GameBase = $env:SkyrimAEPath
        Write-Host "`tCurrent $Folder $a_version | ANNIVERSARY EDITION"
    } elseif ($a_isAE -eq 'FALSE') {
        $GameBase = $env:SkyrimSEPath
        Write-Host "`tCurrent $Folder $a_version | SPECIAL EDITION"
    }

    $MO2Base = "$GameBase/MO2/mods/$a_project"
    
    # binary
    Write-Host "`tCopying binary file..."
    New-Item -Type dir "$MO2Base/SKSE/Plugins" -Force | Out-Null
    Copy-Item "$a_path/$a_project.dll" "$MO2Base/SKSE/Plugins/$a_project.dll" -Force
    Write-Host "`tDone!"

    # configs
    if (Test-Path "$PSScriptRoot/$a_project.ini" -PathType Leaf) {
        Write-Host "`tCopying ini configuration..."
        Copy-Item "$PSScriptRoot/$a_project.ini" "$MO2Base/SKSE/Plugins/$a_project.ini" -Force
        Write-Host "`tDone!"
    }
    if (Test-Path "$PSScriptRoot/$a_project.json" -PathType Leaf) {
        Write-Host "`tCopying json configuration..."
        Copy-Item "$PSScriptRoot/$a_project.json" "$MO2Base/SKSE/Plugins/$a_project.json" -Force
        Write-Host "`tDone!"
    }    
    if (Test-Path "$PSScriptRoot/$a_project.toml" -PathType Leaf) {
        Write-Host "`tCopying toml configuration..."
        Copy-Item "$PSScriptRoot/$a_project.toml" "$MO2Base/SKSE/Plugins/$a_project.toml" -Force
        Write-Host "`tDone!"
    }

    # papyrus
    if (Test-Path "$PSScriptRoot/Scripts/Source/*.psc" -PathType Leaf) {
        Write-Host "`tBuilding papyrus scripts..."
        New-Item -Type dir "$MO2Base/Scripts" -Force | Out-Null
        & "$GameBase/Papyrus Compiler/PapyrusCompiler.exe" "$PSScriptRoot/Scripts/Source" -f="$GameBase/Papyrus Compiler/TESV_Papyrus_Flags.flg" -i="$GameBase/Data/Scripts/Source;./Scripts/Source" -o="$PSScriptRoot/Scripts" -a
        Write-Host "`tDone!"

        Write-Host "`tCopying papyrus scripts..."
        Copy-Item "$PSScriptRoot/Scripts" "$MO2Base" -Recurse -Force
        Write-Host "`tDone!"
    }

    # shockwave
    if (Test-Path "$PSScriptRoot/Interface/*.swf" -PathType Leaf) {
        Write-Host "`tCopying shockwave files..."
        New-Item -Type dir "$MO2Base/Interface" -Force | Out-Null
        Copy-Item "$PSScriptRoot/Interface" "$MO2Base" -Recurse -Force
        Write-Host "`tDone!"
    }
} elseif ($a_mode -eq 'SOURCEGEN') { # cmake sourcelist generation
    Write-Host "`tGenerating CMake sourcelist..."
    Remove-Item "$a_path/sourcelist.cmake" -Force -Confirm:$false -ErrorAction Ignore

    $generated = 'set(SOURCES'
    $generated += $PSScriptRoot | Walk-Files
    if ($a_path) {
        $generated += $a_path | Walk-Files
    }
    $generated += "`n)"
    [IO.File]::WriteAllText("$a_path/sourcelist.cmake", $generated)

    if ($a_version) {
        # update vcpkg.json accordinly
        $vcpkg = [IO.File]::ReadAllText("$PSScriptRoot/vcpkg.json") | ConvertFrom-Json
        $vcpkg.'version-string' = $a_version
        $vcpkg = $vcpkg | ConvertTo-Json
        [IO.File]::WriteAllText("$PSScriptRoot/vcpkg.json", $vcpkg) # damn you encoding
    }
} elseif ($a_mode -eq 'DISTRIBUTE') { # update script to every project
    ((Get-ChildItem 'Plugins' -Directory -Recurse) + (Get-ChildItem 'Library' -Directory -Recurse)) | Resolve-Path -Relative | ForEach-Object {
        if (Test-Path "$_/CMakeLists.txt" -PathType Leaf) {
            Write-Host "`tUpdated <$_>"
            Robocopy.exe '.' "$_" '!Update.ps1' /MT /NJS /NFL /NDL /NJH
        }
    }
}

Write-Host "`t<$Folder> [$a_mode] DONE"