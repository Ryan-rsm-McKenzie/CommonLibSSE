#pragma once

#include "skse64/GameAPI.h"  // Heap

#include "RE/Misc.h"  // _HeapAllocAbstraction()


namespace RE
{
	inline void* Heap_Allocate(std::size_t a_size)
	{
		return ::Heap_Allocate(a_size);
	}


	inline void Heap_Free(void* a_ptr)
	{
		::Heap_Free(a_ptr);
	}


	template<typename T>
	inline T* Heap_Allocate(void)
	{
		return reinterpret_cast<T*>(Heap_Allocate(sizeof(T)));
	}


#define TES_HEAP_REDEFINE_NEW()												\
	static void* operator new(std::size_t a_size)							\
	{ return Heap_Allocate(a_size); }										\
	static void* operator new(std::size_t a_size, const std::nothrow_t&)	\
	{ return Heap_Allocate(a_size); }										\
	static void* operator new(std::size_t a_size, void* a_ptr)				\
	{ return a_ptr; }														\
	static void operator delete(void* a_ptr)								\
	{ Heap_Free(a_ptr); }													\
	static void operator delete(void* a_ptr, const std::nothrow_t &)		\
	{ Heap_Free(a_ptr); }													\
	static void operator delete(void*, void *)								\
	{ }


#define TES_HEAP_REDEFINE_ABSTRACT_NEW()									\
	static void* operator new(std::size_t a_size)							\
	{ return _HeapAllocAbstraction(a_size); }								\
	static void* operator new(std::size_t a_size, const std::nothrow_t&)	\
	{ return _HeapAllocAbstraction(a_size); }								\
	static void* operator new(std::size_t a_size, void* a_ptr)				\
	{ return a_ptr; }														\
	static void operator delete(void* a_ptr)								\
	{ Heap_Free(a_ptr); }													\
	static void operator delete(void* a_ptr, const std::nothrow_t&)			\
	{ Heap_Free(a_ptr); }													\
	static void operator delete(void*, void*)								\
	{ }
}
