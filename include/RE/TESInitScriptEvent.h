#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESInitScriptEvent
	{
		// members
		NiPointer<TESObjectREFR> objectInitialized;	 // 0
	};
	STATIC_ASSERT(sizeof(TESInitScriptEvent) == 0x8);
}
