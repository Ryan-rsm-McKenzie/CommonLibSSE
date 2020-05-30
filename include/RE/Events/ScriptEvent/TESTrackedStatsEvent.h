#pragma once

#include "RE/BSFixedString.h"


namespace RE
{
	struct TESTrackedStatsEvent
	{
	public:
		// members
		BSFixedString stat;	  // 00
		SInt32		  value;  // 08
		UInt32		  pad0C;  // 0C
	};
	STATIC_ASSERT(sizeof(TESTrackedStatsEvent) == 0x10);
}
