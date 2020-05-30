#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESResetEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> object;  // 0
	};
	STATIC_ASSERT(sizeof(TESResetEvent) == 0x8);
}
