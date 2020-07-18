#pragma once

#include "RE/NetImmerse/NiSmartPointer.h"


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
		std::uint8_t			 pad11;		   // 11
		std::uint16_t			 pad12;		   // 12
		std::uint32_t			 pad14;		   // 14
	};
	static_assert(sizeof(TESDeathEvent) == 0x18);
}
