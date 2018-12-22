#include "RE/NiMemory.h"

#include "skse64/GameAPI.h"  // Heap


namespace RE
{
	void* NiMalloc(std::size_t a_size)
	{
		return Heap_Allocate(a_size);
	}


	void NiFree(void* a_ptr)
	{
		if (a_ptr) {
			Heap_Free(a_ptr);
		}
	}
}
