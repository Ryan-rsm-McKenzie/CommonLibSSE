#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESResetEvent
	{
		// members
		NiPointer<TESObjectREFR> ref;	// 0
	};
	STATIC_ASSERT(sizeof(TESResetEvent) == 0x8);
}
