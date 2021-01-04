#pragma once

#include "RE/G/GAllocator.h"
#include "RE/G/GArrayBase.h"
#include "RE/G/GArrayData.h"
#include "RE/G/GArrayDefaultPolicy.h"
#include "RE/G/GStats.h"

namespace RE
{
	template <class T, std::uint32_t SID = GStatGroup::kGStat_Default_Mem, class SizePolicy = GArrayDefaultPolicy>
	class GArray : public GArrayBase<GArrayData<T, GAllocatorGH<T, SID>, SizePolicy>>
	{
	public:
	};
	static_assert(sizeof(GArray<void*>) == 0x18);
}
