#pragma once

#include "RE/BSFixedString.h"


namespace RE
{
	struct BGSFootstepEvent
	{
		// members
		RefHandle		handle;	// 00
		UInt32			pad04;	// 04
		BSFixedString	str;	// 08
	};
	STATIC_ASSERT(sizeof(BGSFootstepEvent) == 0x10);
}
