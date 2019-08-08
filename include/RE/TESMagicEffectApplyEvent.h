#pragma once

#include "RE/FormTypes.h"  // TESObjectREFR


namespace RE
{
	struct TESMagicEffectApplyEvent
	{
		TESObjectREFR*	target;	// 00
		TESObjectREFR*	caster;	// 08
		FormID			formID;	// 10
		UInt32			pad14;	// 14
	};
	STATIC_ASSERT(sizeof(TESMagicEffectApplyEvent) == 0x18);
}
