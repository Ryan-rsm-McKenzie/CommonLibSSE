#pragma once

#include "RE/GAllocatorBaseGH.h"
#include "RE/GConstructorMov.h"
#include "RE/GStats.h"


namespace RE
{
	template <class T, UInt32 SID = GStatGroup::kGStat_Default_Mem>
	struct GAllocatorGH : GAllocatorBaseGH<SID>, GConstructorMov<T>
	{};
}
