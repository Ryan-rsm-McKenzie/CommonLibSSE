#pragma once

#include "RE/Scaleform/GAllocator/GAllocatorBaseGH.h"
#include "RE/Scaleform/GAllocator/GConstructorMov.h"
#include "RE/Scaleform/GStats/GStats.h"


namespace RE
{
	template <class T, UInt32 SID = GStatGroup::kGStat_Default_Mem>
	struct GAllocatorGH : GAllocatorBaseGH<SID>, GConstructorMov<T>
	{};
}
