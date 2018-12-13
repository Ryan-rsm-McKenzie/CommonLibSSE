#pragma once

#include <type_traits>  // underlying_type_t


template <typename EnumType>
constexpr auto to_underlying(EnumType a_typedEnum) noexcept
{
	return static_cast<std::underlying_type_t<EnumType>>(a_typedEnum);
}


//unary ~operator    
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator~ (Enum& val)
{
	val = static_cast<Enum>(~static_cast<std::underlying_type_t<Enum>>(val));
	return val;
}


// & operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator& (Enum lhs, Enum rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(lhs) & static_cast<std::underlying_type_t<Enum>>(rhs));
}


// &= operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator&= (Enum& lhs, Enum rhs)
{
	lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(lhs) & static_cast<std::underlying_type_t<Enum>>(rhs));
	return lhs;
}


//| operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator| (Enum lhs, Enum rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(lhs) | static_cast<std::underlying_type_t<Enum>>(rhs));
}


//|= operator
template <typename Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator|= (Enum& lhs, Enum rhs)
{
	lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(lhs) | static_cast<std::underlying_type_t<Enum>>(rhs));
	return lhs;
}
