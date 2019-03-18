#pragma once

#include "skse64/GameAPI.h"  // Heap

#include <cstdlib>  // size_t
#include <new>  // operator new, operator delete


namespace RE
{
	inline void* Heap_Allocate(std::size_t a_size)
	{
		return ::Heap_Allocate(a_size);
	}


	inline void Heap_Free(void* a_ptr)
	{
		if (a_ptr) {
			::Heap_Free(a_ptr);
		}
	}


	template<typename T>
	inline T* Heap_Allocate(void)
	{
		return reinterpret_cast<T*>(Heap_Allocate(sizeof(T)));
	}
}


#define TES_HEAP_REDEFINE_NEW()																											\
	void*	operator new(std::size_t a_count)													{ return RE::Heap_Allocate(a_count); }	\
	void*	operator new[](std::size_t a_count)													{ return RE::Heap_Allocate(a_count); }	\
	void*	operator new([[maybe_unused]] std::size_t a_count, void* a_plcmnt)					{ return a_plcmnt; }					\
	void*	operator new[]([[maybe_unused]] std::size_t a_count, void* a_plcmnt)				{ return a_plcmnt; }					\
	void	operator delete(void* a_ptr)														{ RE::Heap_Free(a_ptr); }				\
	void	operator delete[](void* a_ptr)														{ RE::Heap_Free(a_ptr); }				\
	void	operator delete([[maybe_unused]] void* a_ptr, [[maybe_unused]] void* a_plcmnt)		{ }										\
	void	operator delete[]([[maybe_unused]] void* a_ptr, [[maybe_unused]] void* a_plcmnt)	{ }
