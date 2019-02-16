#pragma once


namespace RE
{
	class GMemoryHeap;
	struct GSysAllocPaged;


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
		static void*			Alloc(UPInt a_size, const GAllocDebugInfo& a_info);
		static void*			Alloc(UPInt a_size, UPInt a_align, const GAllocDebugInfo& a_info);
		static void*			AllocAutoHeap(const void* a_ptr, UPInt a_size);
		static void*			AllocAutoHeap(const void* a_ptr, UPInt a_size, UPInt a_align);
		static void*			AllocAutoHeap(const void* a_ptr, UPInt a_size, const GAllocDebugInfo& a_info);
		static void*			AllocAutoHeap(const void* a_ptr, UPInt a_size, UPInt a_align, const GAllocDebugInfo& a_info);
		static void*			AllocInHeap(GMemoryHeap* a_heap, UPInt a_size);
		static void*			AllocInHeap(GMemoryHeap* a_heap, UPInt a_size, UPInt a_align);
		static void*			AllocInHeap(GMemoryHeap* a_heap, UPInt a_size, const GAllocDebugInfo& a_info);
		static void*			AllocInHeap(GMemoryHeap* a_heap, UPInt a_size, UPInt a_align, const GAllocDebugInfo& a_info);
		static void*			Realloc(void* a_ptr, UPInt a_newSize);
		static void				Free(void* a_ptr);
		static GMemoryHeap*		GetHeapByAddress(const void* a_ptr);
		static bool				DetectMemoryLeaks();

	protected:
		static GMemoryHeap*&	GetGlobalHeapRef();
	};
}
