#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	struct TESMagicEffectApplyEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> target;       // 00
		NiPointer<TESObjectREFR> caster;       // 08
		FormID                   magicEffect;  // 10
		std::uint32_t            pad14;        // 14
	};
	static_assert(sizeof(TESMagicEffectApplyEvent) == 0x18);
}
