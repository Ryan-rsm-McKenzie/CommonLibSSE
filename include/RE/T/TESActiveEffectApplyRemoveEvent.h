#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	struct TESActiveEffectApplyRemoveEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> caster;                // 00
		NiPointer<TESObjectREFR> target;                // 08
		std::uint16_t            activeEffectUniqueID;  // 10
		bool                     isApplied;             // 12
		std::uint8_t             pad13;                 // 13
		std::uint32_t            pad14;                 // 14
	};
	static_assert(sizeof(TESActiveEffectApplyRemoveEvent) == 0x18);
}
