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

    $vcpkg = [IO.File]::ReadAllText("$PSScriptRoot/vcpkg.json") | ConvertFrom-Json
    if ($vcpkg | Get-Member install-name) {
        $destination = $vcpkg.'install-name'
        $MO2Base = "$GameBase/MO2/mods/$destination"
    } else {
        $MO2Base = "$GameBase/MO2/mods/$a_project"
    }
    
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
        if ($vcpkg | Get-Member script-version) {
            $vcpkg.'script-version' = $env:DKScriptVersion
        } else {
            $vcpkg | Add-Member -Name 'script-version' -Value $env:DKScriptVersion -MemberType NoteProperty
        }
        if ($vcpkg | Get-Member build-config) {
            $vcpkg.'build-config' = $env:BuildConfig
        } else {
            $vcpkg | Add-Member -Name 'build-config' -Value $env:BuildConfig -MemberType NoteProperty
        }
        if ($vcpkg | Get-Member build-target) {
            $vcpkg.'build-target' = $env:BuildTarget
        } else {
            $vcpkg | Add-Member -Name 'build-target' -Value $env:BuildTarget -MemberType NoteProperty
        }
        if (-not ($vcpkg | Get-Member install-name)) {
            $vcpkg | Add-Member -Name 'install-name' -Value $Folder -MemberType NoteProperty
        }
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

# SIG # Begin signature block
# MIIR2wYJKoZIhvcNAQcCoIIRzDCCEcgCAQExCzAJBgUrDgMCGgUAMGkGCisGAQQB
# gjcCAQSgWzBZMDQGCisGAQQBgjcCAR4wJgIDAQAABBAfzDtgWUsITrck0sYpfvNR
# AgEAAgEAAgEAAgEAAgEAMCEwCQYFKw4DAhoFAAQUnPLwdnY9SqQouHG7YRuq0RBw
# fLSggg1BMIIDBjCCAe6gAwIBAgIQNkaQTCtrQ7NPmyNqlKMtlDANBgkqhkiG9w0B
# AQsFADAbMRkwFwYDVQQDDBBBVEEgQXV0aGVudGljb2RlMB4XDTIxMTEyODE1MTMy
# N1oXDTIyMTEyODE1MzMyN1owGzEZMBcGA1UEAwwQQVRBIEF1dGhlbnRpY29kZTCC
# ASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBANoBGMeVEUQXzEw352NicaE9
# H9qoHFmrmW68zQjba83QxL/7J60JXEOJJNfwmpuo3sJ98y2InmjOezppuNLsAAfH
# E280/6I4LYNvNj3HYGlWj9VJw5me7PImeMUJcahxLXTzSaUYBjo4xN/Y4THhKKY6
# CSSgP6ZFfQ2/U/JSuun7UIj7p2FQKfVo+Ig46INmkHN/J/Xp3LoGfFVJLszeLcvR
# RkcNtRM+9goAEJEQOXjWXNNDykyK/4Sewdknd0aKPUgRvZBgdlWvWcEhCamO9jOv
# N8azWT7qOkTLGwZ7EdzzW+6KUA+SjXgeYvFjAEu4Gvj0mIrnSgR7eY4hCdM37o0C
# AwEAAaNGMEQwDgYDVR0PAQH/BAQDAgeAMBMGA1UdJQQMMAoGCCsGAQUFBwMDMB0G
# A1UdDgQWBBQgLXQ3KqF1NorX3f6viGK+8dWA8zANBgkqhkiG9w0BAQsFAAOCAQEA
# cgLeEdX+96c5JJ+WnzABZX4hpjXuIv8E9S+gbuEryEi1ikoe9CfU9atkytG+denQ
# E+7drWb1TGQx4BIOmmNCE3j1vbrzct3aYMIjodDaYPmC/2/5bjuAW14b3Zg1Pull
# 9MaVwH/xxM6iF4KlVzkk42iB7/A3HkgoScXn1n28xVBigvB8wQdZG/sZXmPtTGTE
# 2KdyffvwmkDUBDt1s2/ufPpUpBLMjVDk1dK2Kn3zd29osUL0A42OzkIo/egtu3fz
# 6vt5EH9LceFwEnTnWEE2mZkHcmOiYf0GG+bUwYXoPGd1YX8ZnSozdb66oIpUKSnY
# ZmPzyWZE5c9A8Y6RxPIM9zCCBP4wggPmoAMCAQICEA1CSuC+Ooj/YEAhzhQA8N0w
# DQYJKoZIhvcNAQELBQAwcjELMAkGA1UEBhMCVVMxFTATBgNVBAoTDERpZ2lDZXJ0
# IEluYzEZMBcGA1UECxMQd3d3LmRpZ2ljZXJ0LmNvbTExMC8GA1UEAxMoRGlnaUNl
# cnQgU0hBMiBBc3N1cmVkIElEIFRpbWVzdGFtcGluZyBDQTAeFw0yMTAxMDEwMDAw
# MDBaFw0zMTAxMDYwMDAwMDBaMEgxCzAJBgNVBAYTAlVTMRcwFQYDVQQKEw5EaWdp
# Q2VydCwgSW5jLjEgMB4GA1UEAxMXRGlnaUNlcnQgVGltZXN0YW1wIDIwMjEwggEi
# MA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDC5mGEZ8WK9Q0IpEXKY2tR1zoR
# Qr0KdXVNlLQMULUmEP4dyG+RawyW5xpcSO9E5b+bYc0VkWJauP9nC5xj/TZqgfop
# +N0rcIXeAhjzeG28ffnHbQk9vmp2h+mKvfiEXR52yeTGdnY6U9HR01o2j8aj4S8b
# Ordh1nPsTm0zinxdRS1LsVDmQTo3VobckyON91Al6GTm3dOPL1e1hyDrDo4s1SPa
# 9E14RuMDgzEpSlwMMYpKjIjF9zBa+RSvFV9sQ0kJ/SYjU/aNY+gaq1uxHTDCm2mC
# tNv8VlS8H6GHq756WwogL0sJyZWnjbL61mOLTqVyHO6fegFz+BnW/g1JhL0BAgMB
# AAGjggG4MIIBtDAOBgNVHQ8BAf8EBAMCB4AwDAYDVR0TAQH/BAIwADAWBgNVHSUB
# Af8EDDAKBggrBgEFBQcDCDBBBgNVHSAEOjA4MDYGCWCGSAGG/WwHATApMCcGCCsG
# AQUFBwIBFhtodHRwOi8vd3d3LmRpZ2ljZXJ0LmNvbS9DUFMwHwYDVR0jBBgwFoAU
# 9LbhIB3+Ka7S5GGlsqIlssgXNW4wHQYDVR0OBBYEFDZEho6kurBmvrwoLR1ENt3j
# anq8MHEGA1UdHwRqMGgwMqAwoC6GLGh0dHA6Ly9jcmwzLmRpZ2ljZXJ0LmNvbS9z
# aGEyLWFzc3VyZWQtdHMuY3JsMDKgMKAuhixodHRwOi8vY3JsNC5kaWdpY2VydC5j
# b20vc2hhMi1hc3N1cmVkLXRzLmNybDCBhQYIKwYBBQUHAQEEeTB3MCQGCCsGAQUF
# BzABhhhodHRwOi8vb2NzcC5kaWdpY2VydC5jb20wTwYIKwYBBQUHMAKGQ2h0dHA6
# Ly9jYWNlcnRzLmRpZ2ljZXJ0LmNvbS9EaWdpQ2VydFNIQTJBc3N1cmVkSURUaW1l
# c3RhbXBpbmdDQS5jcnQwDQYJKoZIhvcNAQELBQADggEBAEgc3LXpmiO85xrnIA6O
# Z0b9QnJRdAojR6OrktIlxHBZvhSg5SeBpU0UFRkHefDRBMOG2Tu9/kQCZk3taaQP
# 9rhwz2Lo9VFKeHk2eie38+dSn5On7UOee+e03UEiifuHokYDTvz0/rdkd2NfI1Jp
# g4L6GlPtkMyNoRdzDfTzZTlwS/Oc1np72gy8PTLQG8v1Yfx1CAB2vIEO+MDhXM/E
# EXLnG2RJ2CKadRVC9S0yOIHa9GCiurRS+1zgYSQlT7LfySmoc0NR2r1j1h9bm/cu
# G08THfdKDXF+l7f0P4TrweOjSaH6zqe/Vs+6WXZhiV9+p7SOZ3j5NpjhyyjaW4em
# ii8wggUxMIIEGaADAgECAhAKoSXW1jIbfkHkBdo2l8IVMA0GCSqGSIb3DQEBCwUA
# MGUxCzAJBgNVBAYTAlVTMRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxGTAXBgNVBAsT
# EHd3dy5kaWdpY2VydC5jb20xJDAiBgNVBAMTG0RpZ2lDZXJ0IEFzc3VyZWQgSUQg
# Um9vdCBDQTAeFw0xNjAxMDcxMjAwMDBaFw0zMTAxMDcxMjAwMDBaMHIxCzAJBgNV
# BAYTAlVTMRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxGTAXBgNVBAsTEHd3dy5kaWdp
# Y2VydC5jb20xMTAvBgNVBAMTKERpZ2lDZXJ0IFNIQTIgQXNzdXJlZCBJRCBUaW1l
# c3RhbXBpbmcgQ0EwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC90DLu
# S82Pf92puoKZxTlUKFe2I0rEDgdFM1EQfdD5fU1ofue2oPSNs4jkl79jIZCYvxO8
# V9PD4X4I1moUADj3Lh477sym9jJZ/l9lP+Cb6+NGRwYaVX4LJ37AovWg4N4iPw7/
# fpX786O6Ij4YrBHk8JkDbTuFfAnT7l3ImgtU46gJcWvgzyIQD3XPcXJOCq3fQDpc
# t1HhoXkUxk0kIzBdvOw8YGqsLwfM/fDqR9mIUF79Zm5WYScpiYRR5oLnRlD9lCos
# p+R1PrqYD4R/nzEU1q3V8mTLex4F0IQZchfxFwbvPc3WTe8GQv2iUypPhR3EHTyv
# z9qsEPXdrKzpVv+TAgMBAAGjggHOMIIByjAdBgNVHQ4EFgQU9LbhIB3+Ka7S5GGl
# sqIlssgXNW4wHwYDVR0jBBgwFoAUReuir/SSy4IxLVGLp6chnfNtyA8wEgYDVR0T
# AQH/BAgwBgEB/wIBADAOBgNVHQ8BAf8EBAMCAYYwEwYDVR0lBAwwCgYIKwYBBQUH
# AwgweQYIKwYBBQUHAQEEbTBrMCQGCCsGAQUFBzABhhhodHRwOi8vb2NzcC5kaWdp
# Y2VydC5jb20wQwYIKwYBBQUHMAKGN2h0dHA6Ly9jYWNlcnRzLmRpZ2ljZXJ0LmNv
# bS9EaWdpQ2VydEFzc3VyZWRJRFJvb3RDQS5jcnQwgYEGA1UdHwR6MHgwOqA4oDaG
# NGh0dHA6Ly9jcmw0LmRpZ2ljZXJ0LmNvbS9EaWdpQ2VydEFzc3VyZWRJRFJvb3RD
# QS5jcmwwOqA4oDaGNGh0dHA6Ly9jcmwzLmRpZ2ljZXJ0LmNvbS9EaWdpQ2VydEFz
# c3VyZWRJRFJvb3RDQS5jcmwwUAYDVR0gBEkwRzA4BgpghkgBhv1sAAIEMCowKAYI
# KwYBBQUHAgEWHGh0dHBzOi8vd3d3LmRpZ2ljZXJ0LmNvbS9DUFMwCwYJYIZIAYb9
# bAcBMA0GCSqGSIb3DQEBCwUAA4IBAQBxlRLpUYdWac3v3dp8qmN6s3jPBjdAhO9L
# hL/KzwMC/cWnww4gQiyvd/MrHwwhWiq3BTQdaq6Z+CeiZr8JqmDfdqQ6kw/4stHY
# fBli6F6CJR7Euhx7LCHi1lssFDVDBGiy23UC4HLHmNY8ZOUfSBAYX4k4YU1iRiSH
# Y4yRUiyvKYnleB/WCxSlgNcSR3CzddWThZN+tpJn+1Nhiaj1a5bA9FhpDXzIAbG5
# KHW3mWOFIoxhynmUfln8jA/jb7UBJrZspe6HUSHkWGCbugwtK22ixH67xCUrRwII
# fEmuE7bhfEJCKMYYVs9BNLZmXbZ0e/VWMyIvIjayS6JKldj1po5SMYIEBDCCBAAC
# AQEwLzAbMRkwFwYDVQQDDBBBVEEgQXV0aGVudGljb2RlAhA2RpBMK2tDs0+bI2qU
# oy2UMAkGBSsOAwIaBQCgeDAYBgorBgEEAYI3AgEMMQowCKACgAChAoAAMBkGCSqG
# SIb3DQEJAzEMBgorBgEEAYI3AgEEMBwGCisGAQQBgjcCAQsxDjAMBgorBgEEAYI3
# AgEVMCMGCSqGSIb3DQEJBDEWBBT9s0QVaRHA3lDzpGjG3JXmjZUwiTANBgkqhkiG
# 9w0BAQEFAASCAQAVDZMBqyFQVjUU+axVhcOiNajNzhLc7bJFs1hY2ofMyaf3BNf8
# JpQOT5Qia6ow3KA9c87fkqA6EbcS/2PPOh1rQW2abZiFJB/Yc6f9BkUIuA0uHCtE
# u9EKLpQKTS7YA0Az/BLZYJphl+yD1G6jdABSTDFHdkNKtxRr3pSgs3iQFxb5s1kb
# D29i9zzkwV+a/8QwuSgq0s+WnzZvmto73marGKppBjTnjUmpBst2AvCG5froe8bF
# JTa/9qfhWZg/wsWkCNm2eD6A3YPdPiyCQYnyUJ5jLhAKi/drmx5bj+ht2osRFq0f
# 4CiTwtRqXs166IJ9jyYs8O1uS7Qg1SDUCeRzoYICMDCCAiwGCSqGSIb3DQEJBjGC
# Ah0wggIZAgEBMIGGMHIxCzAJBgNVBAYTAlVTMRUwEwYDVQQKEwxEaWdpQ2VydCBJ
# bmMxGTAXBgNVBAsTEHd3dy5kaWdpY2VydC5jb20xMTAvBgNVBAMTKERpZ2lDZXJ0
# IFNIQTIgQXNzdXJlZCBJRCBUaW1lc3RhbXBpbmcgQ0ECEA1CSuC+Ooj/YEAhzhQA
# 8N0wDQYJYIZIAWUDBAIBBQCgaTAYBgkqhkiG9w0BCQMxCwYJKoZIhvcNAQcBMBwG
# CSqGSIb3DQEJBTEPFw0yMTExMjkxMzA1NDBaMC8GCSqGSIb3DQEJBDEiBCC3Ir3U
# yajc3nry4l0QKPNOJnx7o+Kq3DJajTpiTmKRyjANBgkqhkiG9w0BAQEFAASCAQCk
# 3qLhULpk/1fqXmHRl2Yz8IAlP5dykKbkqbj9cTaJzKInCmcD8M+6GlpqHj3qOP/2
# 3Y4FsDhHR96iq/bQQLYw40BIN/Dhk89fMTbO4EuRzFX/5iT5U2+4PYUL3Iqr6x8T
# mJgrNo3mMe+QkhyHe8IdzLeQjJ2vdxAylp4Y2TcKu4KtHNPFj6Whq0/bFkhn1TKI
# 2CATV0gsMSOmPgvNbtqhi4A0zDvrHxQsrMquXraQqzt14xMQizOE03+MMPGfoFXR
# ry/CEN8VBVIo4nOL8MA2H6bLMtDiaa/g2dewar3KKBIMFuN6yMRtwzGTglkNow2T
# qCtzF5QMmylCX7VgNk/A
# SIG # End signature block
