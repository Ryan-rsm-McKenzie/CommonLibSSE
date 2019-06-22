#pragma once

#include <winnt.h>

#include <type_traits>  // enable_if_t, is_integral


#pragma region InterlockedAnd
#undef InterlockedAnd

template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 2, int> = 0>
Int InterlockedAnd(volatile Int* a_destination, SHORT a_value)
{
	return static_cast<Int>(_InterlockedAnd16(reinterpret_cast<volatile SHORT*>(a_destination), a_value));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 4, int> = 0>
Int InterlockedAnd(volatile Int* a_destination, LONG a_value)
{
	return static_cast<Int>(_InterlockedAnd(reinterpret_cast<volatile LONG*>(a_destination), a_value));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 8, int> = 0>
Int InterlockedAnd(volatile Int* a_destination, LONG64 a_value)
{
	return static_cast<Int>(_InterlockedAnd64(reinterpret_cast<volatile LONG64*>(a_destination), a_value));
}
#pragma endregion InterlockedAnd


#pragma region InterlockedOr
#undef InterlockedOr

template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 2, int> = 0>
Int InterlockedOr(volatile Int* a_destination, SHORT a_value)
{
	return static_cast<Int>(_InterlockedOr16(reinterpret_cast<volatile SHORT*>(a_destination), a_value));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 4, int> = 0>
Int InterlockedOr(volatile Int* a_destination, LONG a_value)
{
	return static_cast<Int>(_InterlockedOr(reinterpret_cast<volatile LONG*>(a_destination), a_value));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 8, int> = 0>
Int InterlockedOr(volatile Int* a_destination, LONG64 a_value)
{
	return static_cast<Int>(_InterlockedOr64(reinterpret_cast<volatile LONG64*>(a_destination), a_value));
}

#pragma endregion InterlockedOr


#pragma region InterlockedXor
#undef InterlockedXor

template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 2, int> = 0>
Int InterlockedXor(volatile Int* a_destination, SHORT a_value)
{
	return static_cast<Int>(_InterlockedXor16(reinterpret_cast<volatile SHORT*>(a_destination), a_value));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 4, int> = 0>
Int InterlockedXor(volatile Int* a_destination, LONG a_value)
{
	return static_cast<Int>(_InterlockedXor(reinterpret_cast<volatile LONG*>(a_destination), a_value));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 8, int> = 0>
Int InterlockedXor(volatile Int* a_destination, LONG64 a_value)
{
	return static_cast<Int>(_InterlockedXor64(reinterpret_cast<volatile LONG64*>(a_destination), a_value));
}
#pragma endregion InterlockedXor


#pragma region InterlockedIncrement
#undef InterlockedIncrement

template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 2, int> = 0>
Int InterlockedIncrement(volatile Int* a_addend)
{
	return static_cast<Int>(_InterlockedIncrement16(reinterpret_cast<volatile SHORT*>(a_addend)));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 4, int> = 0>
Int InterlockedIncrement(volatile Int* a_addend)
{
	return static_cast<Int>(_InterlockedIncrement(reinterpret_cast<volatile LONG*>(a_addend)));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 8, int> = 0>
Int InterlockedIncrement(volatile Int* a_addend)
{
	return static_cast<Int>(_InterlockedIncrement64(reinterpret_cast<volatile LONG64*>(a_addend)));
}
#pragma endregion InterlockedIncrement


#pragma region InterlockedDecrement
#undef InterlockedDecrement

template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 2, int> = 0>
Int InterlockedDecrement(volatile Int* a_addend)
{
	return static_cast<Int>(_InterlockedDecrement16(reinterpret_cast<volatile SHORT*>(a_addend)));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 4, int> = 0>
Int InterlockedDecrement(volatile Int* a_addend)
{
	return static_cast<Int>(_InterlockedDecrement(reinterpret_cast<volatile LONG*>(a_addend)));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 8, int> = 0>
Int InterlockedDecrement(volatile Int* a_addend)
{
	return static_cast<Int>(_InterlockedDecrement64(reinterpret_cast<volatile LONG64*>(a_addend)));
}
#pragma endregion InterlockedDecrement


#pragma region InterlockedAdd
#undef InterlockedAdd

template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 2, int> = 0>
Int InterlockedAdd(volatile Int* a_addend, SHORT a_value)
{
	return static_cast<Int>(_InlineInterlockedAdd16(reinterpret_cast<volatile SHORT*>(a_addend), a_value));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 4, int> = 0>
Int InterlockedAdd(volatile Int* a_addend, LONG a_value)
{
	return static_cast<Int>(_InlineInterlockedAdd(reinterpret_cast<volatile LONG*>(a_addend), a_value));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 8, int> = 0>
Int InterlockedAdd(volatile Int* a_addend, LONG64 a_value)
{
	return static_cast<Int>(_InlineInterlockedAdd64(reinterpret_cast<volatile LONG64*>(a_addend), a_value));
}
#pragma endregion InterlockedAdd


#pragma region InterlockedExchange
#undef InterlockedExchange

template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 2, int> = 0>
Int InterlockedExchange(volatile Int* a_target, SHORT a_value)
{
	return static_cast<Int>(_InterlockedExchange16(reinterpret_cast<volatile SHORT*>(a_target), a_value));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 4, int> = 0>
Int InterlockedExchange(volatile Int* a_target, LONG a_value)
{
	return static_cast<Int>(_InterlockedExchange(reinterpret_cast<volatile LONG*>(a_target), a_value));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 8, int> = 0>
Int InterlockedExchange(volatile Int* a_target, LONG64 a_value)
{
	return static_cast<Int>(_InterlockedExchange64(reinterpret_cast<volatile LONG64*>(a_target), a_value));
}
#pragma endregion InterlockedExchange


#pragma region InterlockedExchangeAdd
#undef InterlockedExchangeAdd

template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 2, int> = 0>
Int InterlockedExchangeAdd(volatile Int* a_addend, SHORT a_value)
{
	return static_cast<Int>(_InterlockedExchangeAdd16(reinterpret_cast<volatile SHORT*>(a_addend), a_value));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 4, int> = 0>
Int InterlockedExchangeAdd(volatile Int* a_addend, LONG a_value)
{
	return static_cast<Int>(_InterlockedExchangeAdd(reinterpret_cast<volatile LONG*>(a_addend), a_value));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 8, int> = 0>
Int InterlockedExchangeAdd(volatile Int* a_addend, LONG64 a_value)
{
	return static_cast<Int>(_InterlockedExchangeAdd64(reinterpret_cast<volatile LONG64*>(a_addend), a_value));
}
#pragma endregion InterlockedExchangeAdd


#pragma region InterlockedCompareExchange
#undef InterlockedCompareExchange

template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 2, int> = 0>
Int InterlockedCompareExchange(volatile Int* a_destination, SHORT a_exchange, SHORT a_comperand)
{
	return static_cast<Int>(_InterlockedCompareExchange16(reinterpret_cast<volatile SHORT*>(a_destination), a_exchange, a_comperand));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 4, int> = 0>
Int InterlockedCompareExchange(volatile Int* a_destination, LONG a_exchange, LONG a_comperand)
{
	return static_cast<Int>(_InterlockedCompareExchange(reinterpret_cast<volatile LONG*>(a_destination), a_exchange, a_comperand));
}


template <class Int, typename std::enable_if_t<std::is_integral<Int>::value && sizeof(Int) == 8, int> = 0>
Int InterlockedCompareExchange(volatile Int* a_destination, LONG64 a_exchange, LONG64 a_comperand)
{
	return static_cast<Int>(_InterlockedCompareExchange64(reinterpret_cast<volatile LONG64*>(a_destination), a_exchange, a_comperand));
}
#pragma endregion InterlockedCompareExchange
