#include "RE/GMemory.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/GMemoryHeap.h"  // GMemoryHeap
#include "RE/Offsets.h"


namespace RE
{
	void GMemory::SetGlobalHeap(GMemoryHeap* a_heap)
	{
		GetGlobalHeapRef() = a_heap;
	}


	GMemoryHeap* GMemory::GetGlobalHeap()
	{
		return GetGlobalHeapRef();
	}


	void GMemory::CreateArena(UPInt a_arena, GSysAllocPaged* a_sysAlloc)
	{
		GetGlobalHeapRef()->CreateArena(a_arena, a_sysAlloc);
	}


	void GMemory::DestroyArena(UPInt a_arena)
	{
		GetGlobalHeapRef()->DestroyArena(a_arena);
	}


	bool GMemory::ArenaIsEmpty(UPInt a_arena)
	{
		return GetGlobalHeapRef()->ArenaIsEmpty(a_arena);
	}


	void* GMemory::Alloc(UPInt a_size)
	{
		return GetGlobalHeapRef()->Alloc(a_size);
	}


	void* GMemory::Alloc(UPInt a_size, UPInt a_align)
	{
		return GetGlobalHeapRef()->Alloc(a_size, a_align);
	}


	void* GMemory::Alloc(UPInt a_size, const GAllocDebugInfo& a_info)
	{
		return GetGlobalHeapRef()->Alloc(a_size, &a_info);
	}


	void* GMemory::Alloc(UPInt a_size, UPInt a_align, const GAllocDebugInfo& a_info)
	{
		return GetGlobalHeapRef()->Alloc(a_size, a_align, &a_info);
	}


	void* GMemory::AllocAutoHeap(const void* a_ptr, UPInt a_size)
	{
		return GetGlobalHeapRef()->AllocAutoHeap(a_ptr, a_size);
	}

	void* GMemory::AllocAutoHeap(const void* a_ptr, UPInt a_size, UPInt a_align)
	{
		return GetGlobalHeapRef()->AllocAutoHeap(a_ptr, a_size, a_align);
	}


	void* GMemory::AllocAutoHeap(const void* a_ptr, UPInt a_size, const GAllocDebugInfo& a_info)
	{
		return GetGlobalHeapRef()->AllocAutoHeap(a_ptr, a_size, &a_info);
	}


	void* GMemory::AllocAutoHeap(const void* a_ptr, UPInt a_size, UPInt a_align, const GAllocDebugInfo& a_info)
	{
		return GetGlobalHeapRef()->AllocAutoHeap(a_ptr, a_size, a_align, &a_info);
	}


	void* GMemory::AllocInHeap(GMemoryHeap* a_heap, UPInt a_size)
	{
		return a_heap->Alloc(a_size);
	}


	void* GMemory::AllocInHeap(GMemoryHeap* a_heap, UPInt a_size, UPInt a_align)
	{
		return a_heap->Alloc(a_size, a_align);
	}


	void* GMemory::AllocInHeap(GMemoryHeap* a_heap, UPInt a_size, const GAllocDebugInfo& a_info)
	{
		return a_heap->Alloc(a_size, &a_info);
	}


	void* GMemory::AllocInHeap(GMemoryHeap* a_heap, UPInt a_size, UPInt a_align, const GAllocDebugInfo& a_info)
	{
		return a_heap->Alloc(a_size, a_align, &a_info);
	}


	void* GMemory::Realloc(void* a_ptr, UPInt a_newSize)
	{
		return GetGlobalHeapRef()->Realloc(a_ptr, a_newSize);
	}


	void GMemory::Free(void* a_ptr)
	{
		return GetGlobalHeapRef()->Free(a_ptr);
	}


	GMemoryHeap* GMemory::GetHeapByAddress(const void* a_ptr)
	{
		return GetGlobalHeapRef()->GetAllocHeap(a_ptr);
	}


	bool GMemory::DetectMemoryLeaks()
	{
		return GetGlobalHeapRef()->DumpMemoryLeaks();
	}


	GMemoryHeap*& GMemory::GetGlobalHeapRef()
	{
		RelocPtr<GMemoryHeap*> globalHeap(SCALEFORM_GLOBAL_HEAP);
		return *globalHeap.GetPtr();
	}
}
