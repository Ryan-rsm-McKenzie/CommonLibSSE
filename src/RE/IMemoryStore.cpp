#include "RE/IMemoryStore.h"


namespace RE
{
	void* IMemoryStore::AllocateAlign(std::size_t a_size, UInt32 a_alignment)
	{
		return AllocateAlignImpl(a_size, a_alignment);
	}


	void IMemoryStore::DeallocateAlign(void* a_freeBlock)
	{
		DeallocateAlignImpl(a_freeBlock);
	}
}
