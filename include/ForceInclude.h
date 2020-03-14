#pragma once

#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0601	 // SSE requires minimum windows 7

#include <WinSock2.h>
#include <xmmintrin.h>

#undef AddForm
#undef far
#undef GetClassName
#undef GetFileAttributes
#undef GetForm
#undef GetObject
#undef LoadIcon
#undef max
#undef min
#undef near
#undef PlaySound
#undef ReplaceText
#undef SetForm

#undef FAR
#undef NEAR
#define FAR
#define NEAR

#pragma warning(disable : 4200)	 // nonstandard extension used : zero-sized array in struct/union
#pragma warning(disable : 4514)	 // 'function' : unreferenced inline function has been removed
#pragma warning(disable : 4710)	 // 'function' : function not inlined
#pragma warning(disable : 4711)	 // function 'function' selected for inline expansion
#pragma warning(disable : 5045)	 // Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified

#undef STATIC_ASSERT
#define STATIC_ASSERT(bool_constexpr) static_assert(bool_constexpr)

#undef __MACRO_JOIN__
#undef __MACRO_JOIN_2__
#undef __MACRO_JOIN_3__
#define __MACRO_JOIN__(a, b)   __MACRO_JOIN_2__(a, b)
#define __MACRO_JOIN_2__(a, b) __MACRO_JOIN_3__(a, b)
#define __MACRO_JOIN_3__(a, b) a##b

#include <cstdint>

using UInt8 = unsigned char;
using UInt16 = unsigned short;
using UInt32 = unsigned long;
using UInt64 = unsigned long long;

using SInt8 = signed char;
using SInt16 = signed short;
using SInt32 = signed long;
using SInt64 = signed long long;

#include "Atomic.h"
#include "Util.h"

#include "RE/BSCoreTypes.h"
#include "RE/Offsets_NiRTTI.h"
#include "RE/Offsets_RTTI.h"
#include "RE/SFTypes.h"
