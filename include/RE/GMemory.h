#pragma once

#include "RE/GMemoryHeap.h"  // GMemoryHeap, GSysAllocPaged, GAllocDebugInfo


namespace RE
{
	class GMemory
	{
	public:
		static void				SetGlobalHeap(GMemoryHeap* a_heap);
		static GMemoryHeap*		GetGlobalHeap();
		static void				CreateArena(UPInt a_arena, GSysAllocPaged* a_sysAlloc);
		static void				DestroyArena(UPInt a_arena);
		static bool				ArenaIsEmpty(UPInt a_arena);
		static void*			Alloc(UPInt a_size);
		static void*			Alloc(UPInt a_size, UPInt a_align);
		static void*			AllocAutoHeap(const void* a_ptr, UPInt a_size);
		static void*			AllocAutoHeap(const void* a_ptr, UPInt a_size, UPInt a_align);
		static void*			AllocInHeap(GMemoryHeap* a_heap, UPInt a_size);
		static void*			AllocInHeap(GMemoryHeap* a_heap, UPInt a_size, UPInt a_align);
		static void*			Realloc(void* a_ptr, UPInt a_newSize);
		static void				Free(void* a_ptr);
		static GMemoryHeap*		GetHeapByAddress(const void* a_ptr);
		static bool				DetectMemoryLeaks();

	protected:
		static GMemoryHeap*&	GetGlobalHeapRef();
	};
}


// Global heap
#define GALLOC(a_sz, id)				RE::GMemory::Alloc((a_sz))
#define GMEMALIGN(a_sz, a_algn, a_id)	RE::GMemory::Alloc((a_sz),(a_algn))
#define GREALLOC(a_ptr, a_sz, a_id)		RE::GMemory::Realloc((a_ptr),(a_sz))
#define GFREE(a_ptr)					RE::GMemory::Free((a_ptr))
#define GFREE_ALIGN(a_sz)				RE::GMemory::Free((a_sz))


// Local heap
#define GHEAP_ALLOC(a_heap, a_sz, a_id)				RE::GMemory::AllocInHeap((a_heap), (a_sz))
#define GHEAP_MEMALIGN(a_heap, a_sz, a_algn, a_id)	RE::GMemory::AllocInHeap((a_heap), (a_sz), (a_algn))
#define GHEAP_AUTO_ALLOC(a_addr, a_sz)				RE::GMemory::AllocAutoHeap((a_addr), (a_sz))
#define GHEAP_AUTO_ALLOC_ID(a_addr, a_sz, a_id)		RE::GMemory::AllocAutoHeap((a_addr), (a_sz))
#define GHEAP_FREE(a_heap, a_ptr)					RE::GMemory::Free((a_ptr))


#define GFC_MEMORY_REDEFINE_NEW_IMPL(a_className, a_check_delete, a_statType)																																										\
	void*	operator new(UPInt a_sz)																				{ void* a_ptr = GALLOC(a_sz, a_statType); return a_ptr; }																		\
	void*	operator new(UPInt a_sz, RE::GMemoryHeap* a_heap)														{ void* a_ptr = GHEAP_ALLOC(a_heap, a_sz, a_statType); return a_ptr; }															\
	void*	operator new(UPInt a_sz, RE::GMemoryHeap* a_heap, int a_blocktype)										{ void* a_ptr = GHEAP_ALLOC(a_heap, a_sz, a_blocktype); return a_ptr; }															\
	void*	operator new(UPInt a_sz, const char* a_filename, int a_line)											{ void* a_ptr = RE::GMemory::Alloc(a_sz, RE::GAllocDebugInfo(a_statType, a_filename, a_line)); return a_ptr; }					\
	void*	operator new(UPInt a_sz, RE::GMemoryHeap* a_heap, const char* a_filename, int a_line)					{ void* a_ptr = RE::GMemory::AllocInHeap(a_heap, a_sz, RE::GAllocDebugInfo(a_statType, a_filename, a_line)); return a_ptr; }	\
	void*	operator new(UPInt a_sz, int a_blocktype, const char* a_filename, int a_line)							{ void* a_ptr = RE::GMemory::Alloc(a_sz, RE::GAllocDebugInfo(a_blocktype, a_filename, a_line)); return a_ptr; }					\
	void*	operator new(UPInt a_sz, RE::GMemoryHeap* a_heap, int a_blocktype, const char* a_filename, int a_line)	{ void* a_ptr = RE::GMemory::AllocInHeap(a_heap, a_sz, RE::GAllocDebugInfo(a_blocktype, a_filename, a_line)); return a_ptr; }


#define GFC_MEMORY_CHECK_DELETE_NONE(a_className, a_ptr)
#define GFC_MEMORY_REDEFINE_NEW(a_className, a_statType) GFC_MEMORY_REDEFINE_NEW_IMPL(a_className, GFC_MEMORY_CHECK_DELETE_NONE, a_statType)
