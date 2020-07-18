#pragma once

#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESLockChangedEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> lockedObject;	// 0
	};
	static_assert(sizeof(TESLockChangedEvent) == 0x8);
}
