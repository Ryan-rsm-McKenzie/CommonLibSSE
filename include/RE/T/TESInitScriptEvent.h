#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	struct TESInitScriptEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> objectInitialized;  // 0
	};
	static_assert(sizeof(TESInitScriptEvent) == 0x8);
}
