#pragma once

#define WINVER		 0x0601	 // Windows 7
#define _WIN32_WINNT 0x0601

#define WIN32_LEAN_AND_MEAN

#ifndef SKSE_CUSTOM_WINDEF

#define NOGDICAPMASKS
#define NOVIRTUALKEYCODES
//#define NOWINMESSAGES
#define NOWINSTYLES
#define NOSYSMETRICS
#define NOMENUS
#define NOICONS
#define NOKEYSTATES
#define NOSYSCOMMANDS
#define NORASTEROPS
#define NOSHOWWINDOW
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCOLOR
//#define NOCTLMGR
#define NODRAWTEXT
#define NOGDI
#define NOKERNEL
//#define NOUSER
#define NONLS
//#define NOMB
#define NOMEMMGR
#define NOMETAFILE
#define NOMINMAX
//#define NOMSG
#define NOOPENFILE
#define NOSCROLL
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC
#define NOWH
#define NOWINOFFSETS
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX

#endif

#define SPDLOG_COMPILED_LIB

#include <Windows.h>

#include <ShlObj.h>
#include <xmmintrin.h>

#include <DirectXMath.h>
#include <d3d9types.h>

#include <algorithm>
#include <array>
#include <bitset>
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
#include <stack>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <utility>
#include <variant>
#include <vector>

#include <nonstd/span.hpp>
#include <spdlog/spdlog.h>

#undef far
#undef GetClassName
#undef GetFileAttributes
#undef LoadIcon
#undef near

#undef FAR
#undef NEAR
#define FAR
#define NEAR

#pragma warning(disable : 4061)	 // enumerator 'identifier' in switch of enum 'enumeration' is not explicitly handled by a case label
#pragma warning(disable : 4200)	 // nonstandard extension used : zero-sized array in struct/union
#pragma warning(disable : 4265)	 // 'type': class has virtual functions, but its non-trivial destructor is not virtual; instances of this class may not be destructed correctly
#pragma warning(disable : 4266)	 // 'function' : no override available for virtual member function from base 'type'; function is hidden
#pragma warning(disable : 4514)	 // 'function' : unreferenced inline function has been removed
#pragma warning(disable : 4582)	 // 'type': constructor is not implicitly called
#pragma warning(disable : 4583)	 // 'type': destructor is not implicitly called
#pragma warning(disable : 4623)	 // 'derived class' : default constructor was implicitly defined as deleted because a base class default constructor is inaccessible or deleted
#pragma warning(disable : 4625)	 // 'derived class' : copy constructor was implicitly defined as deleted because a base class copy constructor is inaccessible or deleted
#pragma warning(disable : 4626)	 // 'derived class' : assignment operator was implicitly defined as deleted because a base class assignment operator is inaccessible or deleted
#pragma warning(disable : 4710)	 // 'function' : function not inlined
#pragma warning(disable : 4711)	 // function 'function' selected for inline expansion
#pragma warning(disable : 4820)	 // 'bytes' bytes padding added after construct 'member_name'
#pragma warning(disable : 5026)	 // 'type': move constructor was implicitly defined as deleted
#pragma warning(disable : 5027)	 // 'type': move assignment operator was implicitly defined as deleted
#pragma warning(disable : 5045)	 // Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
#pragma warning(disable : 5053)	 // support for 'explicit(<expr>)' in C++17 and earlier is a vendor extension
#pragma warning(disable : 5204)	 // 'type': class has virtual functions, but its trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly
#pragma warning(disable : 5220)	 // 'type': a non-static data member with a volatile qualified type no longer implies that compiler generated copy/move constructors and copy/move assignment operators are not trivial

extern "C" IMAGE_DOS_HEADER __ImageBase;

#include "SKSE/Impl/Atomic.h"

namespace SKSE
{
	using namespace std::literals;


	namespace stl
	{
		using nonstd::span;

		template <class CharT>
		using basic_zstring = std::basic_string_view<CharT>;

		using zstring = basic_zstring<char>;
		using zwstring = basic_zstring<wchar_t>;

		namespace detail
		{
			template <class, class, class...>
			struct _can_construct_at :
				std::false_type
			{};

			template <class T, class... Args>
			struct _can_construct_at<
				std::void_t<
					decltype(::new (std::declval<void*>()) T(std::declval<Args>()...))>,
				T,
				Args...> :
				std::true_type
			{};

			template <class T, class... Args>
			struct can_construct_at :
				_can_construct_at<void, T, Args...>
			{};

			template <class T, class... Args>
			inline constexpr bool can_construct_at_v = can_construct_at<T, Args...>::value;
		}


		template <class T>
		struct is_bounded_array :
			std::false_type
		{};

		template <class T, std::size_t N>
		struct is_bounded_array<T[N]> :
			std::true_type
		{};

		template <class T>
		inline constexpr bool is_bounded_array_v = is_bounded_array<T>::value;


		template <class T>
		struct is_unbounded_array :
			std::false_type
		{};

		template <class T>
		struct is_unbounded_array<T[]> :
			std::true_type
		{};

		template <class T>
		inline constexpr bool is_unbounded_array_v = is_unbounded_array<T>::value;


		namespace detail
		{
			template <class CharT>
			[[noreturn]] inline void report_and_fail(basic_zstring<CharT> a_msg)
			{
				const auto [getModuleFileName, messageBox] = []() noexcept {
					if constexpr (std::is_same_v<CharT, char>) {
						return std::make_pair(GetModuleFileNameA, MessageBoxA);
					} else if constexpr (std::is_same_v<CharT, wchar_t>) {
						return std::make_pair(GetModuleFileNameW, MessageBoxW);
					} else {
						static_assert(false);
					}
				}();

				std::vector<CharT> buf;
				buf.reserve(MAX_PATH);
				buf.resize(MAX_PATH / 2);
				std::uint32_t result = 0;
				do {
					buf.resize(buf.size() * 2);
					result = getModuleFileName(
						reinterpret_cast<HINSTANCE>(std::addressof(__ImageBase)),
						buf.data(),
						static_cast<std::uint32_t>(buf.size()));
				} while (result && result == buf.size() && buf.size() <= std::numeric_limits<std::uint32_t>::max());

				const auto filename = [&]() {
					if (result && result != buf.size()) {
						std::filesystem::path p(buf.begin(), buf.begin() + result);
						if constexpr (std::is_same_v<CharT, char>) {
							return p.filename().string();
						} else if constexpr (std::is_same_v<CharT, wchar_t>) {
							return p.filename().wstring();
						} else {
							static_assert(false);
						}
					} else {
						return std::basic_string<CharT>();
					}
				}();
				const auto caption = filename.empty() ? nullptr : filename.data();

				messageBox(nullptr, a_msg.data(), caption, MB_OK);
				std::_Exit(EXIT_FAILURE);
			}
		}


		[[noreturn]] inline void report_and_fail(zstring a_msg) { detail::report_and_fail(a_msg); }
		[[noreturn]] inline void report_and_fail(zwstring a_msg) { detail::report_and_fail(a_msg); }


		template <
			class T,
			class... Args,
			std::enable_if_t<
				std::conjunction_v<
					detail::can_construct_at<T, Args...>,
					std::is_constructible<T, Args...>>,	 // more strict
				int> = 0>
		inline T* construct_at(T* a_ptr, Args&&... a_args)
		{
			return ::new (
				const_cast<void*>(
					static_cast<const volatile void*>(a_ptr)))
				T(std::forward<Args>(a_args)...);
		}


		template <class T>
		inline void destroy_at(T* a_ptr)
		{
			if constexpr (std::is_array_v<T>) {
				for (auto& elem : *a_ptr) {
					destroy_at(std::addressof(elem));
				}
			} else {
				a_ptr->~T();
			}
		}

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

			template <
				class... Args,
				std::enable_if_t<
					std::conjunction_v<
						std::is_same<
							Args,
							enum_type>...>,
					int> = 0>
			constexpr enumeration(Args... a_values) noexcept :
				_impl((static_cast<underlying_type>(a_values) | ...))
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

			[[nodiscard]] explicit constexpr operator bool() const noexcept { return _impl != static_cast<underlying_type>(0); }

			[[nodiscard]] constexpr enum_type		operator*() const noexcept { return get(); }
			[[nodiscard]] constexpr enum_type		get() const noexcept { return static_cast<enum_type>(_impl); }
			[[nodiscard]] constexpr underlying_type underlying() const noexcept { return _impl; }

			template <
				class... Args,
				std::enable_if_t<
					std::conjunction_v<
						std::is_same<
							Args,
							enum_type>...>,
					int> = 0>
			constexpr enumeration& set(Args... a_args) noexcept
			{
				_impl |= (static_cast<underlying_type>(a_args) | ...);
				return *this;
			}

			template <
				class... Args,
				std::enable_if_t<
					std::conjunction_v<
						std::is_same<
							Args,
							enum_type>...>,
					int> = 0>
			constexpr enumeration& reset(Args... a_args) noexcept
			{
				_impl &= ~(static_cast<underlying_type>(a_args) | ...);
				return *this;
			}

			template <
				class... Args,
				std::enable_if_t<
					std::conjunction_v<
						std::is_same<
							Args,
							enum_type>...>,
					int> = 0>
			[[nodiscard]] constexpr bool any(Args... a_args) const noexcept
			{
				return (_impl & (static_cast<underlying_type>(a_args) | ...)) != static_cast<underlying_type>(0);
			}

			template <
				class... Args,
				std::enable_if_t<
					std::conjunction_v<
						std::is_same<
							Args,
							enum_type>...>,
					int> = 0>
			[[nodiscard]] constexpr bool all(Args... a_args) const noexcept
			{
				return (_impl & (static_cast<underlying_type>(a_args) | ...)) == (static_cast<underlying_type>(a_args) | ...);
			}

			template <
				class... Args,
				std::enable_if_t<
					std::conjunction_v<
						std::is_same<
							Args,
							enum_type>...>,
					int> = 0>
			[[nodiscard]] constexpr bool none(Args... a_args) const noexcept
			{
				return (_impl & (static_cast<underlying_type>(a_args) | ...)) == static_cast<underlying_type>(0);
			}

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
	}                                                                                                       \
                                                                                                            \
	template <                                                                                              \
		class E,                                                                                            \
		class U>                                                                                            \
	[[nodiscard]] constexpr bool operator a_op(E a_lhs, enumeration<E, U> a_rhs) noexcept                   \
	{                                                                                                       \
		return a_lhs a_op a_rhs.get();                                                                      \
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
		class U>                                                                                            \
	[[nodiscard]] constexpr auto operator a_op(E a_lhs, enumeration<E, U> a_rhs) noexcept                   \
		->enumeration<E, U>                                                                                 \
	{                                                                                                       \
		return static_cast<E>(static_cast<U>(a_lhs) a_op static_cast<U>(a_rhs.get()));                      \
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
	}                                                                                                       \
                                                                                                            \
	template <                                                                                              \
		class E,                                                                                            \
		class U>                                                                                            \
	constexpr auto operator a_op##=(E& a_lhs, enumeration<E, U> a_rhs) noexcept                             \
		->E&                                                                                                \
	{                                                                                                       \
		return a_lhs = *(a_lhs a_op a_rhs);                                                                 \
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


	inline namespace util
	{
		// owning pointer
		template <
			class T,
			class = std::enable_if_t<
				std::is_pointer_v<T>>>
		using owner = T;


		// non-owning pointer
		template <
			class T,
			class = std::enable_if_t<
				std::is_pointer_v<T>>>
		using observer = T;


		// non-null pointer
		template <
			class T,
			class = std::enable_if_t<
				std::is_pointer_v<T>>>
		using not_null = T;


		template <class T>
		struct ssizeof
		{
			[[nodiscard]] constexpr operator std::ptrdiff_t() const noexcept { return value; }

			[[nodiscard]] constexpr std::ptrdiff_t operator()() const noexcept { return value; }

			static constexpr auto value = static_cast<std::ptrdiff_t>(sizeof(T));
		};


		template <class T>
		inline constexpr auto ssizeof_v = ssizeof<T>::value;


		// + operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		[[nodiscard]] constexpr Enum operator+(Enum a_lhs, Enum a_rhs) noexcept
		{
			using underlying_type_t = std::underlying_type_t<Enum>;
			return static_cast<Enum>(
				static_cast<underlying_type_t>(a_lhs) +
				static_cast<underlying_type_t>(a_rhs));
		}


		// += operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		constexpr Enum& operator+=(Enum& a_lhs, Enum a_rhs) noexcept
		{
			return a_lhs = a_lhs + a_rhs;
		}


		// - operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		[[nodiscard]] constexpr Enum operator-(Enum a_lhs, Enum a_rhs) noexcept
		{
			using underlying_type_t = std::underlying_type_t<Enum>;
			return static_cast<Enum>(
				static_cast<underlying_type_t>(a_lhs) -
				static_cast<underlying_type_t>(a_rhs));
		}


		// -= operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		constexpr Enum& operator-=(Enum& a_lhs, Enum a_rhs) noexcept
		{
			return a_lhs = a_lhs - a_rhs;
		}


		// ~ operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		[[nodiscard]] constexpr Enum operator~(Enum a_val) noexcept
		{
			using underlying_type_t = std::underlying_type_t<Enum>;
			return static_cast<Enum>(~static_cast<underlying_type_t>(a_val));
		}


		// & operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		[[nodiscard]] constexpr Enum operator&(Enum a_lhs, Enum a_rhs) noexcept
		{
			using underlying_type_t = std::underlying_type_t<Enum>;
			return static_cast<Enum>(
				static_cast<underlying_type_t>(a_lhs) &
				static_cast<underlying_type_t>(a_rhs));
		}


		// &= operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		constexpr Enum& operator&=(Enum& a_lhs, Enum a_rhs) noexcept
		{
			return a_lhs = a_lhs & a_rhs;
		}


		// | operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		[[nodiscard]] constexpr Enum operator|(Enum a_lhs, Enum a_rhs) noexcept
		{
			using underlying_type_t = std::underlying_type_t<Enum>;
			return static_cast<Enum>(
				static_cast<underlying_type_t>(a_lhs) |
				static_cast<underlying_type_t>(a_rhs));
		}


		// |= operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		constexpr Enum& operator|=(Enum& a_lhs, Enum a_rhs) noexcept
		{
			return a_lhs = a_lhs | a_rhs;
		}


		// ^ operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		[[nodiscard]] constexpr Enum operator^(Enum a_lhs, Enum a_rhs) noexcept
		{
			using underlying_type_t = std::underlying_type_t<Enum>;
			return static_cast<Enum>(
				static_cast<underlying_type_t>(a_lhs) ^
				static_cast<underlying_type_t>(a_rhs));
		}


		// ^= operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		constexpr Enum& operator^=(Enum& a_lhs, Enum a_rhs) noexcept
		{
			return a_lhs = a_lhs ^ a_rhs;
		}


		// << operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		[[nodiscard]] constexpr Enum operator<<(Enum a_lhs, Enum a_rhs) noexcept
		{
			using underlying_type_t = std::underlying_type_t<Enum>;
			return static_cast<Enum>(
				static_cast<underlying_type_t>(a_lhs)
				<< static_cast<underlying_type_t>(a_rhs));
		}


		// <<= operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		constexpr Enum& operator<<=(Enum& a_lhs, Enum a_rhs) noexcept
		{
			return a_lhs = a_lhs << a_rhs;
		}


		// >> operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		[[nodiscard]] constexpr Enum operator>>(Enum a_lhs, Enum a_rhs) noexcept
		{
			using underlying_type_t = std::underlying_type_t<Enum>;
			return static_cast<Enum>(
				static_cast<underlying_type_t>(a_lhs) >>
				static_cast<underlying_type_t>(a_rhs));
		}


		// >>= operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		constexpr Enum& operator>>=(Enum& a_lhs, Enum a_rhs) noexcept
		{
			return a_lhs = a_lhs >> a_rhs;
		}


		// prefix ++ operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		constexpr Enum& operator++(Enum& a_this) noexcept
		{
			return a_this += static_cast<Enum>(1);
		}


		// postfix ++ operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		[[nodiscard]] constexpr Enum operator++(Enum& a_this, int) noexcept
		{
			auto tmp = a_this;
			++a_this;
			return tmp;
		}


		// prefix -- operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		constexpr Enum& operator--(Enum& a_this) noexcept
		{
			return a_this -= static_cast<Enum>(1);
		}


		// postfix ++ operator
		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		[[nodiscard]] constexpr Enum operator--(Enum& a_this, int) noexcept
		{
			auto tmp = a_this;
			--a_this;
			return tmp;
		}


		template <
			class Enum,
			std::enable_if_t<
				std::is_enum_v<
					Enum>,
				int> = 0>
		[[nodiscard]] constexpr auto to_underlying(Enum a_val) noexcept
		{
			using underlying_type_t = std::underlying_type_t<Enum>;
			return static_cast<underlying_type_t>(a_val);
		}


		template <class To, class From>
		[[nodiscard]] inline To unrestricted_cast(From a_from)
		{
			if constexpr (std::is_same_v<
							  std::remove_cv_t<From>,
							  std::remove_cv_t<To>>) {
				return To{ a_from };

				// From != To
			} else if constexpr (std::is_reference_v<From>) {
				return unrestricted_cast<To>(std::addressof(a_from));

				// From: NOT reference
			} else if constexpr (std::is_reference_v<To>) {
				return *unrestricted_cast<
					std::add_pointer_t<
						std::remove_reference_t<To>>>(a_from);

				// To: NOT reference
			} else if constexpr (std::is_pointer_v<From> &&
								 std::is_pointer_v<To>) {
				return static_cast<To>(
					const_cast<void*>(
						static_cast<const volatile void*>(a_from)));
			} else if constexpr ((std::is_pointer_v<From> && std::is_integral_v<To>) ||
								 (std::is_integral_v<From> && std::is_pointer_v<To>)) {
				return reinterpret_cast<To>(a_from);
			} else {
				union
				{
					std::remove_cv_t<std::remove_reference_t<From>> from;
					std::remove_cv_t<std::remove_reference_t<To>>	to;
				};

				from = std::forward<From>(a_from);
				return to;
			}
		}


		template <class T, class U>
		[[nodiscard]] inline auto adjust_pointer(U* a_ptr, std::ptrdiff_t a_adjust) noexcept
		{
			auto addr = a_ptr ? reinterpret_cast<std::uintptr_t>(a_ptr) + a_adjust : 0;
			if constexpr (std::is_const_v<U> && std::is_volatile_v<U>) {
				return reinterpret_cast<std::add_cv_t<T>*>(addr);
			} else if constexpr (std::is_const_v<U>) {
				return reinterpret_cast<std::add_const_t<T>*>(addr);
			} else if constexpr (std::is_volatile_v<U>) {
				return reinterpret_cast<std::add_volatile_t<T>*>(addr);
			} else {
				return reinterpret_cast<T*>(addr);
			}
		}


		inline void memzero(void* a_dst, std::size_t a_size)
		{
			// msvc stl bug
			const auto	   beg = static_cast</*volatile*/ char*>(a_dst);
			const auto	   end = static_cast</*volatile*/ char*>(a_dst) + a_size;
			constexpr char val = 0;
			std::fill(beg, end, val);
		}


		template <class T>
		inline void memzero(T* a_dst)
		{
			memzero(a_dst, sizeof(T));
		}


		template <
			class... Args,
			std::enable_if_t<
				std::conjunction_v<
					std::is_same<
						bool,
						std::remove_cv_t<
							Args>>...>,
				int> = 0>
		[[nodiscard]] inline auto pun_bits(Args... a_args)
		{
			constexpr auto ARGC = sizeof...(Args);

			std::bitset<ARGC> bits;
			std::size_t		  i = 0;
			((bits[i++] = a_args), ...);

			if constexpr (ARGC <= std::numeric_limits<unsigned long>::digits) {
				return bits.to_ulong();
			} else if constexpr (ARGC <= std::numeric_limits<unsigned long long>::digits) {
				return bits.to_ullong();
			} else {
				static_assert(false);
			}
		}
	}
}

#undef SKSE_MAKE_INCREMENTER_OP
#undef SKSE_MAKE_ENUMERATION_OP
#undef SKSE_MAKE_ARITHMETIC_OP
#undef SKSE_MAKE_LOGICAL_OP

namespace RE
{
	using namespace std::literals;
	using namespace SKSE::util;
	namespace stl = SKSE::stl;
}

namespace REL
{
	using namespace std::literals;
	using namespace SKSE::util;
	namespace stl = SKSE::stl;
}

#include "REL/Relocation.h"

#include "RE/BSCore/BSCoreTypes.h"
#include "RE/Offsets/Offsets.h"
#include "RE/Offsets/Offsets_NiRTTI.h"
#include "RE/Offsets/Offsets_RTTI.h"
#include "RE/Scaleform/GTypes/SFTypes.h"
