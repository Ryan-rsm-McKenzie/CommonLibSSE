#pragma once

#include "skse64_common/Relocation.h"  // RelocationManager

#include <cstdint>  // uintptr_t
#include <type_traits>  // underlying_type_t, is_enum


#define MAKE_STR_HELPER(a_str) #a_str
#define MAKE_STR(a_str) MAKE_STR_HELPER(a_str)

#define EXTRACT_SKSE_MEMBER_FN_ADDR(a_class, a_func, a_castTo)	\
*reinterpret_cast<a_castTo*>(((a_class*)0)->_##a_func##_GetPtr());


template <typename Enum>
constexpr auto to_underlying(Enum a_val) noexcept
{
	return static_cast<std::underlying_type_t<Enum>>(a_val);
}


// ~ operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator~(Enum a_val)
{
	return static_cast<Enum>(~static_cast<std::underlying_type_t<Enum>>(a_val));
}


// & operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator&(Enum a_lhs, Enum a_rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) & static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// &= operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator&=(Enum& a_lhs, Enum a_rhs)
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) & static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// | operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator|(Enum a_lhs, Enum a_rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) | static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// |= operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator|=(Enum& a_lhs, Enum a_rhs)
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) | static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// << operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator<<(Enum a_lhs, Enum a_rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) << static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// <<= operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator<<=(Enum& a_lhs, Enum a_rhs)
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) << static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// >> operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator>>(Enum a_lhs, Enum a_rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) >> static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// >>= operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator>>=(Enum& a_lhs, Enum a_rhs)
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) >> static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// BEGIN
// https://stackoverflow.com/a/30848101

// See http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4502.pdf.
template <typename...>
using void_t = void;


// Primary template handles all types not supporting the operation.
template <typename T, template <typename> class Op, typename = void_t<>>
struct is_detected : std::false_type {};


// Specialization recognizes/validates only types supporting the archetype.
template <typename T, template <typename> class Op>
struct is_detected<T, Op, void_t<Op<T>>> : std::true_type {};

// END


template <class T, class S>
T function_cast(S a_func)
{
	return reinterpret_cast<T>(GetFnAddr(a_func));
}


template <class F> class function_type;


// member function
template <class R, class Cls, class... Args>
class function_type<R(Cls::*)(Args...)>
{
public:
	using type = R(Cls*, Args...);
};


// const member function
template <class R, class Cls, class... Args>
class function_type<R(Cls::*)(Args...) const>
{
public:
	using type = R(const Cls*, Args...);
};


// static function
template <class R, class... Args>
class function_type<R(*)(Args...)>
{
public:
	using type = R(Args...);
};


template <class F> using function_type_t = typename function_type<F>::type;


template <class T>
class RelocUnrestricted
{
public:
	RelocUnrestricted() = delete;


	constexpr RelocUnrestricted(std::uintptr_t a_offset) :
		offset(RelocationManager::s_baseAddr + a_offset)
	{}


	operator T()
	{
		return type;
	}

private:
	union
	{
		T type;
		std::uintptr_t offset;
	};
};
