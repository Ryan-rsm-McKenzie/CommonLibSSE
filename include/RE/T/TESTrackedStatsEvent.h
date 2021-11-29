#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	struct TESTrackedStatsEvent
	{
	public:
		// members
		BSFixedString stat;   // 00
		std::int32_t  value;  // 08
		std::uint32_t pad0C;  // 0C
	};
	static_assert(sizeof(TESTrackedStatsEvent) == 0x10);
}
