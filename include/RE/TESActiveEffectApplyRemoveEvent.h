#pragma once

#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class TESObjectREFR;


	struct TESActiveEffectApplyRemoveEvent
	{
		// members
		NiPointer<TESObjectREFR>	caster;			// 00
		NiPointer<TESObjectREFR>	target;			// 08
		UInt16						effectHandle;	// 10
		bool						apply;			// 12
		UInt8						pad13;			// 13
		UInt32						pad14;			// 14
	};
	STATIC_ASSERT(sizeof(TESActiveEffectApplyRemoveEvent) == 0x18);
}
