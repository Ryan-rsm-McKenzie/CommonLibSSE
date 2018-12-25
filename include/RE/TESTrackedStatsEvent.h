#pragma once

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	struct TESTrackedStatsEvent
	{
		BSFixedString	stat;	// 00
		UInt32			value;	// 08
		UInt32			pad0C;	// 0C
	};
	STATIC_ASSERT(sizeof(TESTrackedStatsEvent) == 0x10);
}
