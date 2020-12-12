#pragma once

#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESResetEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> object;  // 0
	};
	static_assert(sizeof(TESResetEvent) == 0x8);
}
