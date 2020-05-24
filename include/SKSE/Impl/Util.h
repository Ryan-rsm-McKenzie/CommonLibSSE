#pragma once

#include <bitset>
#include <limits>
#include <type_traits>


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
[[nodiscard]] constexpr inline Enum operator+(Enum a_lhs, Enum a_rhs) noexcept
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
constexpr inline Enum& operator+=(Enum& a_lhs, Enum a_rhs) noexcept
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
[[nodiscard]] constexpr inline Enum operator-(Enum a_lhs, Enum a_rhs) noexcept
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
constexpr inline Enum& operator-=(Enum& a_lhs, Enum a_rhs) noexcept
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
[[nodiscard]] constexpr inline Enum operator~(Enum a_val) noexcept
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
[[nodiscard]] constexpr inline Enum operator&(Enum a_lhs, Enum a_rhs) noexcept
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
constexpr inline Enum& operator&=(Enum& a_lhs, Enum a_rhs) noexcept
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
[[nodiscard]] constexpr inline Enum operator|(Enum a_lhs, Enum a_rhs) noexcept
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
constexpr inline Enum& operator|=(Enum& a_lhs, Enum a_rhs) noexcept
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
[[nodiscard]] constexpr inline Enum operator^(Enum a_lhs, Enum a_rhs) noexcept
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
constexpr inline Enum& operator^=(Enum& a_lhs, Enum a_rhs) noexcept
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
[[nodiscard]] constexpr inline Enum operator<<(Enum a_lhs, Enum a_rhs) noexcept
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
constexpr inline Enum& operator<<=(Enum& a_lhs, Enum a_rhs) noexcept
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
[[nodiscard]] constexpr inline Enum operator>>(Enum a_lhs, Enum a_rhs) noexcept
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
constexpr inline Enum& operator>>=(Enum& a_lhs, Enum a_rhs) noexcept
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
constexpr inline Enum& operator++(Enum& a_this) noexcept
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
[[nodiscard]] constexpr inline Enum operator++(Enum& a_this, int) noexcept
{
	using underlying_type_t = std::underlying_type_t<Enum>;
	auto tmp = a_this;
	a_this = static_cast<Enum>(
		static_cast<underlying_type_t>(a_this) +
		static_cast<underlying_type_t>(1));
	return tmp;
}


template <class To, class From>
[[nodiscard]] inline decltype(auto) unrestricted_cast(From a_from) noexcept
{
	using from_t = std::remove_reference_t<From>;

	if constexpr (std::is_same_v<To, From>) {
		return a_from;
	} else if constexpr (std::is_reference_v<To>) {
		using to_t =
			std::add_pointer_t<
				std::remove_reference_t<
					To>>;

		union
		{
			from_t from;
			to_t   to;
		};

		from = a_from;
		return *to;
	} else {
		union
		{
			from_t from;
			To	   to;
		};

		from = a_from;
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


namespace SKSE
{
	namespace Impl
	{
		template <class T>
		struct _is_bool :
			std::false_type
		{};

		template <>
		struct _is_bool<bool> :
			std::true_type
		{};

		template <class T>
		struct is_bool :
			_is_bool<
				std::remove_cv_t<
					T>>
		{};
	}
}


template <
	class... Args,
	std::enable_if_t<
		std::conjunction_v<
			SKSE::Impl::is_bool<
				Args>...>,
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
