#pragma once

#include "RE/BSFixedString.h"


namespace RE
{
	class TESObjectREFR;


	struct BSAnimationGraphEvent
	{
	public:
		// members
		const BSFixedString	 tag;	   // 00
		const TESObjectREFR* holder;   // 08
		const BSFixedString	 payload;  // 10
	};
	STATIC_ASSERT(sizeof(BSAnimationGraphEvent) == 0x18);
}
