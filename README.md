# `CommonLibSSE`
[![C++20](https://img.shields.io/static/v1?label=standard&message=C%2B%2B20&color=blue&logo=c%2B%2B&&logoColor=white&style=flat)](https://en.cppreference.com/w/cpp/compiler_support)
[![Platform](https://img.shields.io/static/v1?label=platform&message=windows&color=dimgray&style=flat)](#)
[![Main CI](https://img.shields.io/github/workflow/status/Ryan-rsm-McKenzie/CommonLibSSE/Main%20CI?logo=github&logoColor=white)](https://github.com/Ryan-rsm-McKenzie/CommonLibSSE/actions/workflows/main_ci.yml)

## Build Dependencies
* [binary_io](https://github.com/Ryan-rsm-McKenzie/binary_io)
* [Boost](https://www.boost.org/)
	* Stl_interfaces
* [spdlog](https://github.com/gabime/spdlog)
* [fmt](https://github.com/fmtlib/fmt)
* [Visual Studio Community 2022](https://visualstudio.microsoft.com/vs/preview/) (or later)
	* Desktop development with C++

## End User Dependencies
* [Address Library for SKSE Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/32444)
* [SKSE64](https://skse.silverlock.org/)

## Development
* [Address Library for SKSE Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/32444)
* [clang-format 12.0.0](https://github.com/llvm/llvm-project/releases) (or later)
* [CMake](https://cmake.org/)
* [vcpkg](https://github.com/microsoft/vcpkg)

## Notes
* CommonLib is incompatible with SKSE and is intended to replace it as a static dependency. However, you will still need the runtime component.

## Tutorial
Learn how to build your very first SKSE plugin using CommonLib by following [this video tutorial](https://www.youtube.com/watch?v=FLRhsrQ8mqw).
