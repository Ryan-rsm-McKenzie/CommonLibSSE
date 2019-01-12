#pragma once

#include <type_traits>  // underlying_type_t, is_enum


#define MAKE_STR_HELPER(a_str) #a_str
#define MAKE_STR(a_str) MAKE_STR_HELPER(a_str)


template <typename Enum>
constexpr auto to_underlying(Enum a_val) noexcept
{
	return static_cast<std::underlying_type_t<Enum>>(a_val);
}


// unary ~operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator ~(Enum a_val)
{
	a_val = static_cast<Enum>(~static_cast<std::underlying_type_t<Enum>>(a_val));
	return a_val;
}


// & operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator &(Enum a_lhs, Enum a_rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) & static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// &= operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator &=(Enum& a_lhs, Enum a_rhs)
{
	a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) & static_cast<std::underlying_type_t<Enum>>(a_rhs));
	return a_lhs;
}


// | operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator |(Enum a_lhs, Enum a_rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) | static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// |= operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator |=(Enum& a_lhs, Enum a_rhs)
{
	a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) | static_cast<std::underlying_type_t<Enum>>(a_rhs));
	return a_lhs;
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
