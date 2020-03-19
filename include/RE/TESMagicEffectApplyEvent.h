#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESMagicEffectApplyEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> target;	   // 00
		NiPointer<TESObjectREFR> caster;	   // 08
		FormID					 magicEffect;  // 10
		UInt32					 pad14;		   // 14
	};
	STATIC_ASSERT(sizeof(TESMagicEffectApplyEvent) == 0x18);
}
