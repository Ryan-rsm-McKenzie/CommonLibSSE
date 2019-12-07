#pragma once

#include <bitset>
#include <type_traits>


#define MAKE_STR_HELPER(a_str) #a_str
#define MAKE_STR(a_str) MAKE_STR_HELPER(a_str)


template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr auto to_underlying(Enum a_val) noexcept
{
	return static_cast<std::underlying_type_t<Enum>>(a_val);
}


// + operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator+(Enum a_lhs, Enum a_rhs) noexcept
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) + static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// += operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator+=(Enum& a_lhs, Enum a_rhs) noexcept
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) + static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// - operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator-(Enum a_lhs, Enum a_rhs) noexcept
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) - static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// -= operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator-=(Enum& a_lhs, Enum a_rhs) noexcept
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) - static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// ~ operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator~(Enum a_val) noexcept
{
	return static_cast<Enum>(~static_cast<std::underlying_type_t<Enum>>(a_val));
}


// & operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator&(Enum a_lhs, Enum a_rhs) noexcept
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) & static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// &= operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator&=(Enum& a_lhs, Enum a_rhs) noexcept
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) & static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// | operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator|(Enum a_lhs, Enum a_rhs) noexcept
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) | static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// |= operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator|=(Enum& a_lhs, Enum a_rhs) noexcept
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) | static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// << operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator<<(Enum a_lhs, Enum a_rhs) noexcept
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) << static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// <<= operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator<<=(Enum& a_lhs, Enum a_rhs) noexcept
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) << static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// >> operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator>>(Enum a_lhs, Enum a_rhs) noexcept
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) >> static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// >>= operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator>>=(Enum& a_lhs, Enum a_rhs) noexcept
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) >> static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// prefix ++ operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator++(Enum& a_this) noexcept
{
	return a_this = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_this) + static_cast<std::underlying_type_t<Enum>>(1));
}


// postfix ++ operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator++(Enum& a_this, int) noexcept
{
	auto tmp = a_this;
	a_this = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_this) + static_cast<std::underlying_type_t<Enum>>(1));
	return tmp;
}


template <class To, class From, class Enable = void>
To unrestricted_cast(From a_from)
{
	union
	{
		From from;
		To to;
	};

	from = a_from;
	return to;
}


template <class To, class From, std::enable_if_t<std::is_same<To, From>::value>>
To unrestricted_cast(From a_from)
{
	return a_from;
}


template <class F> struct function_type;


// member function
template <class R, class Cls, class... Args>
struct function_type<R(Cls::*)(Args...)>
{
	using type = R(Cls*, Args...);
};


// variadic member function
template <class R, class Cls, class... Args>
struct function_type<R(Cls::*)(Args..., ...)>
{
	using type = R(Cls*, Args..., ...);
};


// const member function
template <class R, class Cls, class... Args>
struct function_type<R(Cls::*)(Args...) const>
{
	using type = R(const Cls*, Args...);
};


// variadic const member function
template <class R, class Cls, class... Args>
struct function_type<R(Cls::*)(Args..., ...) const>
{
	using type = R(const Cls*, Args..., ...);
};


// static function
template <class R, class... Args>
struct function_type<R(*)(Args...)>
{
	using type = R(Args...);
};


// variadic static function
template <class R, class... Args>
struct function_type<R(*)(Args..., ...)>
{
	using type = R(Args..., ...);
};


template <class F> using function_type_t = typename function_type<F>::type;


namespace SKSE
{
	namespace Impl
	{
		namespace
		{
			template <class Enable, class... Args> struct _ulong_compat : std::false_type {};
			template <class... Args> struct _ulong_compat<typename std::enable_if_t<(sizeof...(Args) <= 32)>, Args...> : std::true_type {};
		}
		template <class... Args> struct ulong_compat : _ulong_compat<void, Args...> {};

		namespace
		{
			template <class Enable, class... Args> struct _ullong_compat : std::false_type {};
			template <class... Args> struct _ullong_compat<typename std::enable_if_t<(sizeof...(Args) > 32) && (sizeof...(Args) <= 64)>, Args...> : std::true_type {};
		}
		template <class... Args> struct ullong_compat : _ullong_compat<void, Args...> {};

		namespace
		{
			template <class T> struct _is_bool : std::false_type {};
			template <> struct _is_bool<bool> : std::true_type {};
		}
		template <class T> struct is_bool : _is_bool<T> {};
	}
}


template <class... Args, typename std::enable_if_t<std::conjunction<SKSE::Impl::is_bool<Args>..., SKSE::Impl::ulong_compat<Args...>>::value, int> = 0>
unsigned long pun_bits(Args... a_args)
{
	std::bitset<sizeof...(Args)> bits;
	std::size_t i = 0;
	((bits[i++] = a_args), ...);
	return bits.to_ulong();
}


template <class... Args, typename std::enable_if_t<std::conjunction<SKSE::Impl::is_bool<Args>..., SKSE::Impl::ullong_compat<Args...>>::value, int> = 0>
unsigned long long pun_bits(Args... a_args)
{
	std::bitset<sizeof...(Args)> bits;
	std::size_t i = 0;
	((bits[i++] = a_args), ...);
	return bits.to_ullong();
}


inline void memzero(void* a_dst, std::size_t a_size)
{
	volatile auto beg = static_cast<char*>(a_dst);
	volatile auto end = static_cast<char*>(a_dst) + a_size;
	constexpr char val = 0;
	std::fill(beg, end, val);
}


template <class T>
inline void memzero(T* a_dst)
{
	return memzero(a_dst, sizeof(T));
}
