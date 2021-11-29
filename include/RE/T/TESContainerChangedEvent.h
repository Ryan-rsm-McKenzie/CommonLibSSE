#pragma once

#include "RE/B/BSPointerHandle.h"

namespace RE
{
	struct TESContainerChangedEvent
	{
	public:
		// members
		FormID          oldContainer;  // 00
		FormID          newContainer;  // 04
		FormID          baseObj;       // 08
		std::int32_t    itemCount;     // 0C
		ObjectRefHandle reference;     // 10
		std::uint16_t   uniqueID;      // 14
		std::uint16_t   pad16;         // 16
	};
	static_assert(sizeof(TESContainerChangedEvent) == 0x18);
}
