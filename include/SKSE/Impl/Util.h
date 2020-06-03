#pragma once

#include <bitset>
#include <cassert>
#include <cstddef>
#include <limits>
#include <memory>
#include <type_traits>
#include <utility>


#define MAKE_STR_HELPER(a_str) #a_str
#define MAKE_STR(a_str)		   MAKE_STR_HELPER(a_str)


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
	using underlying_type_t = std::underlying_type_t<Enum>;
	return a_lhs = static_cast<Enum>(
			   static_cast<underlying_type_t>(a_lhs) +
			   static_cast<underlying_type_t>(a_rhs));
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
	using underlying_type_t = std::underlying_type_t<Enum>;
	return a_lhs = static_cast<Enum>(
			   static_cast<underlying_type_t>(a_lhs) -
			   static_cast<underlying_type_t>(a_rhs));
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
	using underlying_type_t = std::underlying_type_t<Enum>;
	return a_lhs = static_cast<Enum>(
			   static_cast<underlying_type_t>(a_lhs) &
			   static_cast<underlying_type_t>(a_rhs));
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
	using underlying_type_t = std::underlying_type_t<Enum>;
	return a_lhs = static_cast<Enum>(
			   static_cast<underlying_type_t>(a_lhs) |
			   static_cast<underlying_type_t>(a_rhs));
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
	using underlying_type_t = std::underlying_type_t<Enum>;
	return a_lhs = static_cast<Enum>(
			   static_cast<underlying_type_t>(a_lhs) ^
			   static_cast<underlying_type_t>(a_rhs));
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
		static_cast<underlying_type_t>(a_lhs) << static_cast<underlying_type_t>(a_rhs));
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
	using underlying_type_t = std::underlying_type_t<Enum>;
	return a_lhs = static_cast<Enum>(
			   static_cast<underlying_type_t>(a_lhs) << static_cast<underlying_type_t>(a_rhs));
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
		static_cast<underlying_type_t>(a_lhs) >> static_cast<underlying_type_t>(a_rhs));
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
	using underlying_type_t = std::underlying_type_t<Enum>;
	return a_lhs = static_cast<Enum>(
			   static_cast<underlying_type_t>(a_lhs) >>
			   static_cast<underlying_type_t>(a_rhs));
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
	using underlying_type_t = std::underlying_type_t<Enum>;
	return a_this = static_cast<Enum>(
			   static_cast<underlying_type_t>(a_this) +
			   static_cast<underlying_type_t>(1));
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
	using underlying_type_t = std::underlying_type_t<Enum>;
	auto tmp = a_this;
	a_this = static_cast<Enum>(
		static_cast<underlying_type_t>(a_this) +
		static_cast<underlying_type_t>(1));
	return tmp;
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
			static_cast<void*>(
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
	volatile auto  beg = static_cast<char*>(a_dst);
	volatile auto  end = static_cast<char*>(a_dst) + a_size;
	constexpr char VAL = 0;
	std::fill(beg, end, VAL);
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


template <class T>
struct ssizeof
{
	[[nodiscard]] constexpr operator std::ptrdiff_t() const noexcept { return value; }

	[[nodiscard]] constexpr std::ptrdiff_t operator()() const noexcept { return value; }

	static constexpr auto value = static_cast<std::ptrdiff_t>(sizeof(T));
};


template <class T>
inline constexpr auto ssizeof_v = ssizeof<T>::value;


namespace SKSE
{
	inline namespace Util
	{
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
	}
}


namespace RE
{
	using namespace SKSE::Util;
}
