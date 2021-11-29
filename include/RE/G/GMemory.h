#pragma once

#include "RE/G/GMemoryHeap.h"

namespace RE
{
	class GMemory
	{
	public:
		static void         SetGlobalHeap(GMemoryHeap* a_heap);
		static GMemoryHeap* GetGlobalHeap();
		static void         CreateArena(UPInt a_arena, GSysAllocPaged* a_sysAlloc);
		static void         DestroyArena(UPInt a_arena);
		static bool         ArenaIsEmpty(UPInt a_arena);
		static void*        Alloc(UPInt a_count);
		static void*        Alloc(UPInt a_count, UPInt a_al);
		static void*        AllocAutoHeap(const void* a_ptr, UPInt a_count);
		static void*        AllocAutoHeap(const void* a_ptr, UPInt a_count, UPInt a_al);
		static void*        AllocInHeap(GMemoryHeap* a_heap, UPInt a_count);
		static void*        AllocInHeap(GMemoryHeap* a_heap, UPInt a_count, UPInt a_al);
		static void*        Realloc(void* a_ptr, UPInt a_newCount);
		static void         Free(void* a_ptr);
		static void         FreeInHeap(GMemoryHeap* a_heap, void* a_ptr);
		static GMemoryHeap* GetHeapByAddress(const void* a_ptr);
		static bool         DetectMemoryLeaks();

	protected:
		static GMemoryHeap*& GetGlobalHeapRef();
	};
}

// Global heap
#define GALLOC(a_count) RE::GMemory::Alloc((a_count))
#define GMEMALIGN(a_sz, a_al) RE::GMemory::Alloc((a_count), (a_al))
#define GREALLOC(a_ptr, a_count) RE::GMemory::Realloc((a_ptr), (a_count))
#define GFREE(a_ptr) RE::GMemory::Free((a_ptr))
#define GFREE_ALIGN(a_count) RE::GMemory::Free((a_count))

// Local heap
#define GHEAP_ALLOC(a_heap, a_count) RE::GMemory::AllocInHeap((a_heap), (a_count))
#define GHEAP_MEMALIGN(a_heap, a_count, a_al) RE::GMemory::AllocInHeap((a_heap), (a_count), (a_al))
#define GHEAP_AUTO_ALLOC(a_addr, a_count) RE::GMemory::AllocAutoHeap((a_addr), (a_count))
#define GHEAP_FREE(a_heap, a_ptr) RE::GMemory::FreeInHeap((a_heap), (a_ptr))

#define GFC_MEMORY_REDEFINE_NEW_IMPL(a_className, a_check_delete, a_statType)                                   \
	void* operator new(std::size_t a_count) { return GALLOC(a_count); }                                         \
	void* operator new[](std::size_t a_count) { return GALLOC(a_count); }                                       \
	void* operator new([[maybe_unused]] std::size_t a_count, void* a_plcmnt) { return a_plcmnt; }               \
	void* operator new[]([[maybe_unused]] std::size_t a_count, void* a_plcmnt) { return a_plcmnt; }             \
	void* operator new(std::size_t a_count, RE::GMemoryHeap* a_heap) { return GHEAP_ALLOC(a_heap, a_count); }   \
	void* operator new[](std::size_t a_count, RE::GMemoryHeap* a_heap) { return GHEAP_ALLOC(a_heap, a_count); } \
	void  operator delete(void* a_ptr) { GFREE(a_ptr); }                                                        \
	void  operator delete[](void* a_ptr) { GFREE(a_ptr); }                                                      \
	void  operator delete([[maybe_unused]] void* a_ptr, [[maybe_unused]] void* a_plcmnt) {}                     \
	void  operator delete[]([[maybe_unused]] void* a_ptr, [[maybe_unused]] void* a_plcmnt) {}                   \
	void  operator delete(void* a_ptr, RE::GMemoryHeap* a_heap) { GHEAP_FREE(a_heap, a_ptr); }

#define GFC_MEMORY_CHECK_DELETE_NONE(a_className, a_ptr)
#define GFC_MEMORY_REDEFINE_NEW(a_className, a_statType) GFC_MEMORY_REDEFINE_NEW_IMPL(a_className, GFC_MEMORY_CHECK_DELETE_NONE, a_statType)
