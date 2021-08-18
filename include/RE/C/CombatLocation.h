#pragma once

#include "RE/N/NiPoint3.h"

namespace RE
{
	class TESForm;

	struct CombatLocation
	{
		// members
		NiPoint3 pos;               // 00
		TESForm* cellOrWorldSpace;  // 0C
	};
	static_assert(sizeof(CombatLocation) == 0x18);
}
