#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	enum class ACTOR_COMBAT_STATE
	{
		kNone = 0,
		kCombat = 1,
		kSearching = 2
	};

	struct TESCombatEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR>                            actor;        // 00
		NiPointer<TESObjectREFR>                            targetActor;  // 08
		stl::enumeration<ACTOR_COMBAT_STATE, std::uint32_t> newState;     // 10
		std::uint32_t                                       pad14{ 0 };   // 14
	};
	static_assert(sizeof(TESCombatEvent) == 0x18);
}
