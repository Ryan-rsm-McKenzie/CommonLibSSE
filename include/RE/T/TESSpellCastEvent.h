#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	struct TESSpellCastEvent
	{
	public:
		// members
		TESObjectREFR* object;  // 00
		FormID         spell;   // 08
	};
	static_assert(sizeof(TESSpellCastEvent) == 0x10);
}
