#pragma once

#include "RE/GAllocatorBaseGH.h"  // GAllocatorBaseGH
#include "RE/GConstructorMov.h"  // GConstructorMov
#include "RE/GStats.h"  // GStatGroup


namespace RE
{
	template <class T, GStatGroup SID = GStatGroup::kGStat_Default_Mem> struct GAllocatorGH : GAllocatorBaseGH<SID>, GConstructorMov<T> {};
}
