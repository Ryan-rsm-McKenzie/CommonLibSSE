#pragma once

#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESInitScriptEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> objectInitialized;	 // 0
	};
	STATIC_ASSERT(sizeof(TESInitScriptEvent) == 0x8);
}
