#pragma once

#include "RE/GMemory.h"  // GMemory
#include "RE/GStats.h"  // GStatGroup


namespace RE
{
	template<GStatGroup SID = GStatGroup::kGStat_Default_Mem>
	class GAllocatorBaseGH
	{
	public:
		enum { kStatID = SID };


		static void* Alloc(UPInt a_size)
		{
			return GMemory::Alloc(a_size);
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
	STATIC_ASSERT(sizeof(GAllocatorBaseGH<>) == 0x1);
}
