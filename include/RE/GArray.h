#pragma once

#include "RE/GAllocator.h"  // GAllocatorGH
#include "RE/GArrayBase.h"  // GArrayBase
#include "RE/GArrayData.h"  // GArrayData
#include "RE/GArrayDefaultPolicy.h"  // GArrayDefaultPolicy
#include "RE/GStats.h"  // GStatGroup


namespace RE
{
	template<class T, UInt32 SID = GStatGroup::kGStat_Default_Mem, class SizePolicy = GArrayDefaultPolicy>
	class GArray : public GArrayBase<GArrayData<T, GAllocatorGH<T, SID>, SizePolicy>>
	{
	public:
	};
	STATIC_ASSERT(sizeof(GArray<void*>) == 0x18);
}
