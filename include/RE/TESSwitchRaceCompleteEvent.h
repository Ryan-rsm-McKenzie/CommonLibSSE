#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESSwitchRaceCompleteEvent
	{
		// members
		NiPointer<TESObjectREFR> ref;	// 0
	};
	STATIC_ASSERT(sizeof(TESSwitchRaceCompleteEvent) == 0x8);
}
