#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <concepts>
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
#include <span>
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

static_assert(
	std::is_integral_v<std::time_t> && sizeof(std::time_t) == sizeof(std::size_t),
	"wrap std::time_t instead");

#pragma warning(push)
#include <boost/stl_interfaces/iterator_interface.hpp>
#include <spdlog/spdlog.h>
#pragma warning(pop)

#include "SKSE/Impl/WinAPI.h"

namespace SKSE
{
	using namespace std::literals;

	namespace stl
	{
		template <class CharT>
		using basic_zstring = std::basic_string_view<CharT>;

		using zstring = basic_zstring<char>;
		using zwstring = basic_zstring<wchar_t>;

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

		[[noreturn]] inline void report_and_fail(std::string_view a_msg, source_location a_loc = source_location::current())
		{
			const auto body = [&]() {
				constexpr std::array directories{
					"include/"sv,
					"src/"sv,
				};

				const std::filesystem::path p = a_loc.file_name();
				const auto					filename = p.generic_string();
				std::string_view			fileview = filename;

				constexpr auto npos = std::string::npos;
				std::size_t	   pos = npos;
				std::size_t	   off = 0;
				for (const auto& dir : directories) {
					pos = fileview.find(dir);
					if (pos != npos) {
						off = dir.length();
						break;
					}
				}

				if (pos != npos) {
					fileview = fileview.substr(pos + off);
				}

				return fmt::format(FMT_STRING("{}({}): {}"), fileview, a_loc.line(), a_msg);
			}();

			const auto caption = []() -> std::string {
				const auto		  maxPath = WinAPI::GetMaxPath();
				std::vector<char> buf;
				buf.reserve(maxPath);
				buf.resize(maxPath / 2);
				std::uint32_t result = 0;
				do {
					buf.resize(buf.size() * 2);
					result = WinAPI::GetModuleFileName(
						WinAPI::GetCurrentModule(),
						buf.data(),
						static_cast<std::uint32_t>(buf.size()));
				} while (result && result == buf.size() && buf.size() <= std::numeric_limits<std::uint32_t>::max());

				if (result && result != buf.size()) {
					std::filesystem::path p(buf.begin(), buf.begin() + result);
					return p.filename().string();
				} else {
					return {};
				}
			}();

			spdlog::log(
				spdlog::source_loc{
					a_loc.file_name(),
					static_cast<int>(a_loc.line()),
					a_loc.function_name() },
				spdlog::level::critical,
				a_msg);
			WinAPI::MessageBox(nullptr, body.c_str(), (caption.empty() ? nullptr : caption.c_str()), 0);
			WinAPI::TerminateProcess(WinAPI::GetCurrentProcess(), EXIT_FAILURE);
		}

		template <class EF>									   //
		requires(std::invocable<std::remove_reference_t<EF>>)  //
			class scope_exit
		{
		public:
			// 1)
			template <class Fn>
			explicit scope_exit(Fn&& a_fn)	//
				noexcept(std::is_nothrow_constructible_v<EF, Fn> ||
						 std::is_nothrow_constructible_v<EF, Fn&>)	//
				requires(!std::is_same_v<std::remove_cvref_t<Fn>, scope_exit> &&
						 std::is_constructible_v<EF, Fn>)
			{
				static_assert(std::invocable<Fn>);

				if constexpr (!std::is_lvalue_reference_v<Fn> &&
							  std::is_nothrow_constructible_v<EF, Fn>) {
					_fn.emplace(std::forward<Fn>(a_fn));
				} else {
					_fn.emplace(a_fn);
				}
			}

			// 2)
			scope_exit(scope_exit&& a_rhs)	//
				noexcept(std::is_nothrow_move_constructible_v<EF> ||
						 std::is_nothrow_copy_constructible_v<EF>)	//
				requires(std::is_nothrow_move_constructible_v<EF> ||
						 std::is_copy_constructible_v<EF>)
			{
				static_assert(!(std::is_nothrow_move_constructible_v<EF> && !std::is_move_constructible_v<EF>));
				static_assert(!(!std::is_nothrow_move_constructible_v<EF> && !std::is_copy_constructible_v<EF>));

				if (a_rhs.active()) {
					if constexpr (std::is_nothrow_move_constructible_v<EF>) {
						_fn.emplace(std::forward<EF>(*a_rhs._fn));
					} else {
						_fn.emplace(a_rhs._fn);
					}
					a_rhs.release();
				}
			}

			// 3)
			scope_exit(const scope_exit&) = delete;

			~scope_exit() noexcept
			{
				if (_fn.has_value()) {
					(*_fn)();
				}
			}

			void release() noexcept { _fn.reset(); }

		private:
			[[nodiscard]] bool active() const noexcept { return _fn.has_value(); }

			std::optional<std::remove_reference_t<EF>> _fn;
		};

		template <class EF>
		scope_exit(EF) -> scope_exit<EF>;

		template <
			class Enum,
			class Underlying = std::underlying_type_t<Enum>>
		class enumeration
		{
		public:
			using enum_type = Enum;
			using underlying_type = Underlying;

			static_assert(std::is_enum_v<enum_type>, "enum_type must be an enum");
			static_assert(std::is_integral_v<underlying_type>, "underlying_type must be an integral");

			constexpr enumeration() noexcept = default;

			constexpr enumeration(const enumeration&) noexcept = default;

			constexpr enumeration(enumeration&&) noexcept = default;

			template <class U2>
			constexpr enumeration(enumeration<Enum, U2> a_rhs) noexcept :
				_impl(static_cast<underlying_type>(a_rhs.get()))
			{}

			template <class... Args>
			constexpr enumeration(Args... a_values) noexcept  //
				requires(std::same_as<Args, enum_type>&&...) :
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

			template <class... Args>
			constexpr enumeration& set(Args... a_args) noexcept	 //
				requires(std::same_as<Args, enum_type>&&...)
			{
				_impl |= (static_cast<underlying_type>(a_args) | ...);
				return *this;
			}

			template <class... Args>
			constexpr enumeration& reset(Args... a_args) noexcept  //
				requires(std::same_as<Args, enum_type>&&...)
			{
				_impl &= ~(static_cast<underlying_type>(a_args) | ...);
				return *this;
			}

			template <class... Args>
			[[nodiscard]] constexpr bool any(Args... a_args) const noexcept	 //
				requires(std::same_as<Args, enum_type>&&...)
			{
				return (_impl & (static_cast<underlying_type>(a_args) | ...)) != static_cast<underlying_type>(0);
			}

			template <class... Args>
			[[nodiscard]] constexpr bool all(Args... a_args) const noexcept	 //
				requires(std::same_as<Args, enum_type>&&...)
			{
				return (_impl & (static_cast<underlying_type>(a_args) | ...)) == (static_cast<underlying_type>(a_args) | ...);
			}

			template <class... Args>
			[[nodiscard]] constexpr bool none(Args... a_args) const noexcept  //
				requires(std::same_as<Args, enum_type>&&...)
			{
				return (_impl & (static_cast<underlying_type>(a_args) | ...)) == static_cast<underlying_type>(0);
			}

		private :
			underlying_type _impl{ 0 };
		};

		template <class... Args>
		enumeration(Args...) -> enumeration<
			std::common_type_t<Args...>,
			std::underlying_type_t<
				std::common_type_t<Args...>>>;
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
		const auto tmp = a_lhs;                                                              \
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

		template <class T>
		class atomic_ref :
			public std::atomic_ref<std::remove_cv_t<T>>
		{
		private:
			using super = std::atomic_ref<std::remove_cv_t<T>>;

		public:
			using value_type = typename super::value_type;

			explicit atomic_ref(T& a_obj) noexcept(std::is_nothrow_constructible_v<super, value_type&>) :
				super(const_cast<value_type&>(a_obj))
			{}

			using super::super;
			using super::operator=;
		};

		template <class T>
		atomic_ref(T&) -> atomic_ref<T>;

		template class atomic_ref<std::int8_t>;
		template class atomic_ref<std::uint8_t>;
		template class atomic_ref<std::int16_t>;
		template class atomic_ref<std::uint16_t>;
		template class atomic_ref<std::int32_t>;
		template class atomic_ref<std::uint32_t>;
		template class atomic_ref<std::int64_t>;
		template class atomic_ref<std::uint64_t>;

		static_assert(atomic_ref<std::int8_t>::is_always_lock_free);
		static_assert(atomic_ref<std::uint8_t>::is_always_lock_free);
		static_assert(atomic_ref<std::int16_t>::is_always_lock_free);
		static_assert(atomic_ref<std::uint16_t>::is_always_lock_free);
		static_assert(atomic_ref<std::int32_t>::is_always_lock_free);
		static_assert(atomic_ref<std::uint32_t>::is_always_lock_free);
		static_assert(atomic_ref<std::int64_t>::is_always_lock_free);
		static_assert(atomic_ref<std::uint64_t>::is_always_lock_free);
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

		template <class T, class U>
		[[nodiscard]] auto adjust_pointer(U* a_ptr, std::ptrdiff_t a_adjust) noexcept
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

		template <class To, class From>
		[[nodiscard]] To unrestricted_cast(From a_from)
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

		template <class T>
		void memzero(volatile T* a_ptr, std::size_t a_size = sizeof(T))
		{
			const auto	   begin = reinterpret_cast<volatile char*>(a_ptr);
			constexpr char val{ 0 };
			std::fill_n(begin, a_size, val);
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
				static_assert(false && sizeof...(Args));
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
	using namespace ::std::literals;
	using namespace ::SKSE::util;
	namespace stl = ::SKSE::stl;
	namespace WinAPI = ::SKSE::WinAPI;
}

namespace REL
{
	using namespace ::std::literals;
	using namespace ::SKSE::util;
	namespace stl = ::SKSE::stl;
	namespace WinAPI = ::SKSE::WinAPI;
}

#include "REL/Relocation.h"

#include "RE/Offsets.h"
#include "RE/Offsets_NiRTTI.h"
#include "RE/Offsets_RTTI.h"

#include "RE/B/BSCoreTypes.h"
#include "RE/S/SFTypes.h"
