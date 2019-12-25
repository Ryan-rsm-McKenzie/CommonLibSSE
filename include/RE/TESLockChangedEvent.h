#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESLockChangedEvent
	{
		// members
		NiPointer<TESObjectREFR> ref;	// 0
	};
	STATIC_ASSERT(sizeof(TESLockChangedEvent) == 0x8);
}
