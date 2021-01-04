#include "RE/I/IMemoryStore.h"

namespace RE
{
	void* IMemoryStore::AllocateAlign(std::size_t a_size, std::uint32_t a_alignment)
	{
		return AllocateAlignImpl(a_size, a_alignment);
	}

	void IMemoryStore::DeallocateAlign(void*& a_freeBlock)
	{
		DeallocateAlignImpl(a_freeBlock);
	}
}
