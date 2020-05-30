#pragma once

#include "RE/GAllocator.h"
#include "RE/GArrayBase.h"
#include "RE/GArrayData.h"
#include "RE/GArrayDefaultPolicy.h"
#include "RE/GStats.h"


namespace RE
{
	template <class T, UInt32 SID = GStatGroup::kGStat_Default_Mem, class SizePolicy = GArrayDefaultPolicy>
	class GArray : public GArrayBase<GArrayData<T, GAllocatorGH<T, SID>, SizePolicy>>
	{
	public:
	};
	STATIC_ASSERT(sizeof(GArray<void*>) == 0x18);
}
