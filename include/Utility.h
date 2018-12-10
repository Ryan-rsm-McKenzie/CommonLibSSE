#pragma once

#include <type_traits>  // underlying_type_t


namespace RE
{
	template <typename EnumType>
	constexpr auto to_underlying(EnumType a_typedEnum) noexcept
	{
		return static_cast<std::underlying_type_t<EnumType>>(a_typedEnum);
	}
}


#define MAKE_BITWISE_OPERATORS(type)																																				\
	inline friend std::underlying_type_t<type> operator&(const type a_lhs, const type a_rhs) { return (std::underlying_type_t<type>)a_lhs & (std::underlying_type_t<type>)a_rhs; }	\
	inline friend std::underlying_type_t<type> operator|(const type a_lhs, const type a_rhs) { return (std::underlying_type_t<type>)a_lhs | (std::underlying_type_t<type>)a_rhs; }