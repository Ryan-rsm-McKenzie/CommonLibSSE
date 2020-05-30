#pragma once

#include "RE/Scaleform/GAllocator/GAllocator.h"
#include "RE/Scaleform/GArray/GArrayBase.h"
#include "RE/Scaleform/GArray/GArrayData.h"
#include "RE/Scaleform/GArray/GArrayDefaultPolicy.h"
#include "RE/Scaleform/GStats/GStats.h"


namespace RE
{
	template <class T, UInt32 SID = GStatGroup::kGStat_Default_Mem, class SizePolicy = GArrayDefaultPolicy>
	class GArray : public GArrayBase<GArrayData<T, GAllocatorGH<T, SID>, SizePolicy>>
	{
	public:
	};
	STATIC_ASSERT(sizeof(GArray<void*>) == 0x18);
}
