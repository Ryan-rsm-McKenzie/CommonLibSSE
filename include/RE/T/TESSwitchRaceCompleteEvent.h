#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	struct TESSwitchRaceCompleteEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> subject;  // 0
	};
	static_assert(sizeof(TESSwitchRaceCompleteEvent) == 0x8);
}
