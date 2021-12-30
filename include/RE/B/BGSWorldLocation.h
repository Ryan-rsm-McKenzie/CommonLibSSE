#pragma once

#include "RE/N/NiPoint3.h"

namespace RE
{
	class TESForm;

	struct BGSWorldLocation
	{
		// members
		NiPoint3 pos;               // 00
		TESForm* cellOrWorldSpace;  // 0C
	};
	static_assert(sizeof(BGSWorldLocation) == 0x18);
}
