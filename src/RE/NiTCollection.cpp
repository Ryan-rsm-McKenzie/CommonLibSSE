#include "RE/NiTCollection.h"

#include "RE/Memory.h"  // malloc, free


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
