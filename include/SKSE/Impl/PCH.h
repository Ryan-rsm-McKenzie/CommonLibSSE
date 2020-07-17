#pragma once

#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0601	 // SSE requires minimum windows 7

#include <WinSock2.h>  // must come first

#include <KnownFolders.h>
#include <ShlObj.h>
#include <xmmintrin.h>

#include <DirectXMath.h>
#include <d3d9types.h>

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <istream>
#include <iterator>
#include <limits>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <optional>
#include <regex>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

#include <nonstd/span.hpp>
#include <spdlog/sinks/base_sink.h>
#include <spdlog/spdlog.h>

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
#pragma warning(disable : 5053)	 // support for 'explicit(<expr>)' in C++17 and earlier is a vendor extension

#undef STATIC_ASSERT
#define STATIC_ASSERT(bool_constexpr) static_assert(bool_constexpr)

#undef XBYAK_NO_OP_NAMES
#define XBYAK_NO_OP_NAMES

using UInt8 = unsigned char;
using UInt16 = unsigned short;
using UInt32 = unsigned long;
using UInt64 = unsigned long long;

using SInt8 = signed char;
using SInt16 = signed short;
using SInt32 = signed long;
using SInt64 = signed long long;

#include "SKSE/Impl/Atomic.h"
#include "SKSE/Impl/Util.h"

namespace SKSE
{
	using namespace std::literals;

	namespace stl
	{
		using nonstd::span;

		using zstring = std::string_view;
		using zwstring = std::wstring_view;

		struct source_location
		{
		public:
			constexpr source_location() noexcept = default;
			constexpr source_location(const source_location&) noexcept = default;
			constexpr source_location(source_location&&) noexcept = default;

			~source_location() noexcept = default;

			constexpr source_location& operator=(const source_location&) noexcept = default;
			constexpr source_location& operator=(source_location&&) noexcept = default;

			[[nodiscard]] static constexpr source_location current(
				std::uint_least32_t a_line = __builtin_LINE(),
				std::uint_least32_t a_column = __builtin_COLUMN(),
				const char*			a_fileName = __builtin_FILE(),
				const char*			a_functionName = __builtin_FUNCTION()) noexcept { return { a_line, a_column, a_fileName, a_functionName }; }

			[[nodiscard]] constexpr std::uint_least32_t line() const noexcept { return _line; }
			[[nodiscard]] constexpr std::uint_least32_t column() const noexcept { return _column; }
			[[nodiscard]] constexpr const char*			file_name() const noexcept { return _fileName; }
			[[nodiscard]] constexpr const char*			function_name() const noexcept { return _functionName; }

		protected:
			constexpr source_location(
				std::uint_least32_t a_line,
				std::uint_least32_t a_column,
				const char*			a_fileName,
				const char*			a_functionName) noexcept :
				_line(a_line),
				_column(a_column),
				_fileName(a_fileName),
				_functionName(a_functionName)
			{}

		private:
			std::uint_least32_t _line{ 0 };
			std::uint_least32_t _column{ 0 };
			const char*			_fileName{ "" };
			const char*			_functionName{ "" };
		};

		template <class, class, class = void>
		class enumeration;

		template <
			class Enum,
			class Underlying>
		class enumeration<
			Enum,
			Underlying,
			std::enable_if_t<
				std::conjunction_v<
					std::is_enum<Enum>,
					std::is_integral<Underlying>>>>
		{
		public:
			using enum_type = Enum;
			using underlying_type = Underlying;

			constexpr enumeration() noexcept = default;

			constexpr enumeration(const enumeration&) noexcept = default;

			constexpr enumeration(enumeration&&) noexcept = default;

			template <class U2>
			constexpr enumeration(enumeration<Enum, U2> a_rhs) noexcept :
				_impl(static_cast<underlying_type>(a_rhs.get()))
			{}

			constexpr enumeration(enum_type a_value) noexcept :
				_impl(static_cast<underlying_type>(a_value))
			{}

			~enumeration() noexcept = default;

			constexpr enumeration& operator=(const enumeration&) noexcept = default;
			constexpr enumeration& operator=(enumeration&&) noexcept = default;

			template <class U2>
			constexpr enumeration& operator=(enumeration<Enum, U2> a_rhs) noexcept
			{
				_impl = static_cast<underlying_type>(a_rhs.get());
			}

			constexpr enumeration& operator=(enum_type a_value) noexcept
			{
				_impl = static_cast<underlying_type>(a_value);
				return *this;
			}

			[[nodiscard]] explicit constexpr operator bool() const noexcept { return _impl != 0; }

			[[nodiscard]] constexpr enum_type operator*() const noexcept { return get(); }
			[[nodiscard]] constexpr enum_type get() const noexcept { return static_cast<enum_type>(_impl); }

		private:
			underlying_type _impl{ 0 };
		};

		template <class E>
		enumeration(E) -> enumeration<E, std::underlying_type_t<E>>;
	}
}

#define SKSE_MAKE_LOGICAL_OP(a_op)                                                                          \
	template <                                                                                              \
		class E,                                                                                            \
		class U1,                                                                                           \
		class U2>                                                                                           \
	[[nodiscard]] constexpr bool operator a_op(enumeration<E, U1> a_lhs, enumeration<E, U2> a_rhs) noexcept \
	{                                                                                                       \
		return a_lhs.get() a_op a_rhs.get();                                                                \
	}                                                                                                       \
                                                                                                            \
	template <                                                                                              \
		class E,                                                                                            \
		class U>                                                                                            \
	[[nodiscard]] constexpr bool operator a_op(enumeration<E, U> a_lhs, E a_rhs) noexcept                   \
	{                                                                                                       \
		return a_lhs.get() a_op a_rhs;                                                                      \
	}

#define SKSE_MAKE_ARITHMETIC_OP(a_op)                                                        \
	template <                                                                               \
		class E,                                                                             \
		class U>                                                                             \
	[[nodiscard]] constexpr auto operator a_op(enumeration<E, U> a_enum, U a_shift) noexcept \
		->enumeration<E, U>                                                                  \
	{                                                                                        \
		return static_cast<E>(static_cast<U>(a_enum.get()) a_op a_shift);                    \
	}                                                                                        \
                                                                                             \
	template <                                                                               \
		class E,                                                                             \
		class U>                                                                             \
	constexpr auto operator a_op##=(enumeration<E, U>& a_enum, U a_shift) noexcept           \
		->enumeration<E, U>&                                                                 \
	{                                                                                        \
		return a_enum = a_enum a_op a_shift;                                                 \
	}

#define SKSE_MAKE_ENUMERATION_OP(a_op)                                                                      \
	template <                                                                                              \
		class E,                                                                                            \
		class U1,                                                                                           \
		class U2>                                                                                           \
	[[nodiscard]] constexpr auto operator a_op(enumeration<E, U1> a_lhs, enumeration<E, U2> a_rhs) noexcept \
		->enumeration<E, std::common_type_t<U1, U2>>                                                        \
	{                                                                                                       \
		return static_cast<E>(static_cast<U1>(a_lhs.get()) a_op static_cast<U2>(a_rhs.get()));              \
	}                                                                                                       \
                                                                                                            \
	template <                                                                                              \
		class E,                                                                                            \
		class U>                                                                                            \
	[[nodiscard]] constexpr auto operator a_op(enumeration<E, U> a_lhs, E a_rhs) noexcept                   \
		->enumeration<E, U>                                                                                 \
	{                                                                                                       \
		return static_cast<E>(static_cast<U>(a_lhs.get()) a_op static_cast<U>(a_rhs));                      \
	}                                                                                                       \
                                                                                                            \
	template <                                                                                              \
		class E,                                                                                            \
		class U1,                                                                                           \
		class U2>                                                                                           \
	constexpr auto operator a_op##=(enumeration<E, U1>& a_lhs, enumeration<E, U2> a_rhs) noexcept           \
		->enumeration<E, U1>&                                                                               \
	{                                                                                                       \
		return a_lhs = a_lhs a_op a_rhs;                                                                    \
	}                                                                                                       \
                                                                                                            \
	template <                                                                                              \
		class E,                                                                                            \
		class U>                                                                                            \
	constexpr auto operator a_op##=(enumeration<E, U>& a_lhs, E a_rhs) noexcept                             \
		->enumeration<E, U>&                                                                                \
	{                                                                                                       \
		return a_lhs = a_lhs a_op a_rhs;                                                                    \
	}

#define SKSE_MAKE_INCREMENTER_OP(a_op)                                                       \
	template <                                                                               \
		class E,                                                                             \
		class U>                                                                             \
	constexpr auto operator a_op##a_op(enumeration<E, U>& a_lhs) noexcept                    \
		->enumeration<E, U>&                                                                 \
	{                                                                                        \
		return a_lhs a_op## = static_cast<E>(1);                                             \
	}                                                                                        \
                                                                                             \
	template <                                                                               \
		class E,                                                                             \
		class U>                                                                             \
	[[nodiscard]] constexpr auto operator a_op##a_op(enumeration<E, U>& a_lhs, int) noexcept \
		->enumeration<E, U>                                                                  \
	{                                                                                        \
		auto	   tmp = a_lhs;                                                              \
		a_op##a_op a_lhs;                                                                    \
		return tmp;                                                                          \
	}

namespace SKSE
{
	namespace stl
	{
		template <
			class E,
			class U>
		[[nodiscard]] constexpr auto operator~(enumeration<E, U> a_enum) noexcept
			-> enumeration<E, U>
		{
			return static_cast<E>(~static_cast<U>(a_enum.get()));
		}

		SKSE_MAKE_LOGICAL_OP(==);
		SKSE_MAKE_LOGICAL_OP(!=);
		SKSE_MAKE_LOGICAL_OP(<);
		SKSE_MAKE_LOGICAL_OP(<=);
		SKSE_MAKE_LOGICAL_OP(>);
		SKSE_MAKE_LOGICAL_OP(>=);

		SKSE_MAKE_ARITHMETIC_OP(<<);
		SKSE_MAKE_ENUMERATION_OP(<<);
		SKSE_MAKE_ARITHMETIC_OP(>>);
		SKSE_MAKE_ENUMERATION_OP(>>);

		SKSE_MAKE_ENUMERATION_OP(|);
		SKSE_MAKE_ENUMERATION_OP(&);
		SKSE_MAKE_ENUMERATION_OP(^);

		SKSE_MAKE_ENUMERATION_OP(+);
		SKSE_MAKE_ENUMERATION_OP(-);

		SKSE_MAKE_INCREMENTER_OP(+);  // ++
		SKSE_MAKE_INCREMENTER_OP(-);  // --
	}
}

#undef SKSE_MAKE_INCREMENTER_OP
#undef SKSE_MAKE_ENUMERATION_OP
#undef SKSE_MAKE_ARITHMETIC_OP
#undef SKSE_MAKE_LOGICAL_OP

namespace RE
{
	using namespace std::literals;
	namespace stl = SKSE::stl;
}

namespace REL
{
	using namespace std::literals;
	namespace stl = SKSE::stl;
}

#include "REL/Relocation.h"

#include "RE/BSCore/BSCoreTypes.h"
#include "RE/Offsets/Offsets.h"
#include "RE/Offsets/Offsets_NiRTTI.h"
#include "RE/Offsets/Offsets_RTTI.h"
#include "RE/Scaleform/GTypes/SFTypes.h"
