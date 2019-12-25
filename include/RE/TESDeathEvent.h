#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESDeathEvent
	{
		// members
		NiPointer<TESObjectREFR>	victim;	// 00
		NiPointer<TESObjectREFR>	killer;	// 08
		bool						isDead;	// 10
		UInt8						pad11;	// 11
		UInt16						pad12;	// 12
		UInt32						pad14;	// 14
	};
	STATIC_ASSERT(sizeof(TESDeathEvent) == 0x18);
}
