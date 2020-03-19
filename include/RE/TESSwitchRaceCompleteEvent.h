#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESSwitchRaceCompleteEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> subject;  // 0
	};
	STATIC_ASSERT(sizeof(TESSwitchRaceCompleteEvent) == 0x8);
}
