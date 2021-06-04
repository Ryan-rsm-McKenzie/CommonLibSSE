#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	struct TESActivateEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> objectActivated;  // 00
		NiPointer<TESObjectREFR> actionRef;        // 08
	};
	static_assert(sizeof(TESActivateEvent) == 0x10);
}
