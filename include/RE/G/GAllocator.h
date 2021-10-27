#pragma once

#include "RE/G/GAllocatorBaseGH.h"
#include "RE/G/GAllocatorBaseLH.h"
#include "RE/G/GConstructorMov.h"
#include "RE/G/GStats.h"

namespace RE
{
	template <class T, std::uint32_t SID = GStatGroup::kGStat_Default_Mem>
	struct GAllocatorGH : GAllocatorBaseGH<SID>, GConstructorMov<T>
	{};

	template <class T, std::uint32_t SID = GStatGroup::kGStat_Default_Mem>
	struct GAllocatorLH : GAllocatorBaseLH<SID>, GConstructorMov<T>
	{};
}
