#include "RE/NiTCollection.h"

#include "RE/TESMemoryManager.h"  // malloc, free


namespace RE
{
	void* NiMalloc(std::size_t a_count)
	{
		return malloc(a_count);
	}


	void NiFree(void* a_ptr)
	{
		free(a_ptr);
	}
}
