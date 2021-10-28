#pragma once

#include "RE/G/GMemory.h"
#include "RE/G/GStats.h"

namespace RE
{
	template <std::uint32_t SID = GStatGroup::kGStat_Default_Mem>
	class GAllocatorBaseLH
	{
	public:
		enum
		{
			kStatID = SID
		};

		static void* Alloc(const void* a_heapAddr, UPInt a_size)
		{
			return GMemory::AllocAutoHeap(a_heapAddr, a_size);
		}

		static void* Realloc(void* a_ptr, UPInt a_newSize)
		{
			return GMemory::Realloc(a_ptr, a_newSize);
		}

		static void Free(void* a_ptr)
		{
			GMemory::Free(a_ptr);
		}
	};
	static_assert(sizeof(GAllocatorBaseLH<>) == 0x1);
}
