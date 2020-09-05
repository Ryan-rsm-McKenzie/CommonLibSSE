#pragma once

#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESActivateEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> objectActivated;  // 00
		NiPointer<TESObjectREFR> actionRef;		   // 08
	};
	static_assert(sizeof(TESActivateEvent) == 0x10);
}
