#pragma once

#include "skse64_common/Relocation.h"  // RelocationManager
#include "skse64/GameRTTI.h"  // Runtime_DynamicCast

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


// + operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator+(Enum a_lhs, Enum a_rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) + static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// += operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator+=(Enum& a_lhs, Enum a_rhs)
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) + static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// - operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator-(Enum a_lhs, Enum a_rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) - static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// -= operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator-=(Enum& a_lhs, Enum a_rhs)
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) - static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// ~ operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator~(Enum a_val)
{
	return static_cast<Enum>(~static_cast<std::underlying_type_t<Enum>>(a_val));
}


// & operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator&(Enum a_lhs, Enum a_rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) & static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// &= operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator&=(Enum& a_lhs, Enum a_rhs)
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) & static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// | operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator|(Enum a_lhs, Enum a_rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) | static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// |= operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator|=(Enum& a_lhs, Enum a_rhs)
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) | static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// << operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator<<(Enum a_lhs, Enum a_rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) << static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// <<= operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator<<=(Enum& a_lhs, Enum a_rhs)
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) << static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// >> operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum operator>>(Enum a_lhs, Enum a_rhs)
{
	return static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) >> static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// >>= operator
template <class Enum, typename std::enable_if_t<std::is_enum<Enum>::value, int> = 0>
constexpr inline Enum& operator>>=(Enum& a_lhs, Enum a_rhs)
{
	return a_lhs = static_cast<Enum>(static_cast<std::underlying_type_t<Enum>>(a_lhs) >> static_cast<std::underlying_type_t<Enum>>(a_rhs));
}


// BEGIN
// https://stackoverflow.com/a/30848101
// See http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4502.pdf.


// Primary template handles all types not supporting the operation.
template <typename T, template <typename> class Op, typename = std::void_t<>>
struct is_detected : std::false_type {};


// Specialization recognizes/validates only types supporting the archetype.
template <typename T, template <typename> class Op>
struct is_detected<T, Op, std::void_t<Op<T>>> : std::true_type {};
// END


namespace { template <class V> using remove_cvpr_t = std::remove_pointer_t<std::remove_reference_t<std::remove_cv_t<V>>>; }
template<class T, class U>
T skyrim_cast(U a_from)
{
	return static_cast<T>(Runtime_DynamicCast(static_cast<void*>(a_from), remove_cvpr_t<T>::RTTI, remove_cvpr_t<U>::RTTI));
}


template <class T, class U>
T unrestricted_cast(U a_from)
{
	union
	{
		U from;
		T to;
	};

	from = a_from;
	return to;
}


template <class T, class U>
T function_cast(U a_func)
{
	union
	{
		std::uintptr_t addr;
		T type;
	};

	addr = GetFnAddr(a_func);
	return type;
}


template <class F> class function_type;


// member function
template <class R, class Cls, class... Args>
class function_type<R(Cls::*)(Args...)>
{
public:
	using type = R(Cls*, Args...);
};


// variadic member function
template <class R, class Cls, class... Args>
class function_type<R(Cls::*)(Args..., ...)>
{
public:
	using type = R(Cls*, Args..., ...);
};


// const member function
template <class R, class Cls, class... Args>
class function_type<R(Cls::*)(Args...) const>
{
public:
	using type = R(const Cls*, Args...);
};


// variadic const member function
template <class R, class Cls, class... Args>
class function_type<R(Cls::*)(Args..., ...) const>
{
public:
	using type = R(const Cls*, Args..., ...);
};


// static function
template <class R, class... Args>
class function_type<R(*)(Args...)>
{
public:
	using type = R(Args...);
};


// variadic static function
template <class R, class... Args>
class function_type<R(*)(Args..., ...)>
{
public:
	using type = R(Args..., ...);
};


template <class F> using function_type_t = typename function_type<F>::type;


template <class T>
class RelocUnrestricted
{
public:
	RelocUnrestricted() = delete;


	constexpr RelocUnrestricted(std::uintptr_t a_offset) :
		_offset(RelocationManager::s_baseAddr + a_offset)
	{}


	operator T()
	{
		return _type;
	}


	T GetType()
	{
		return _type;
	}


	std::uintptr_t GetUIntPtr()
	{
		return _offset;
	}

private:
	union
	{
		T _type;
		std::uintptr_t _offset;
	};
};


template <>
class RelocUnrestricted<std::uintptr_t>
{
public:
	RelocUnrestricted() = delete;


	constexpr RelocUnrestricted(std::uintptr_t a_offset) :
		_offset(RelocationManager::s_baseAddr + a_offset)
	{}


	operator std::uintptr_t()
	{
		return _offset;
	}


	std::uintptr_t GetType()
	{
		return _offset;
	}


	std::uintptr_t GetUIntPtr()
	{
		return _offset;
	}

private:
	std::uintptr_t _offset;
};
