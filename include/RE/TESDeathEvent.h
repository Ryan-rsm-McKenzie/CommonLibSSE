#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESDeathEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> actorDying;   // 00
		NiPointer<TESObjectREFR> actorKiller;  // 08
		bool					 dead;		   // 10
		UInt8					 pad11;		   // 11
		UInt16					 pad12;		   // 12
		UInt32					 pad14;		   // 14
	};
	STATIC_ASSERT(sizeof(TESDeathEvent) == 0x18);
}
