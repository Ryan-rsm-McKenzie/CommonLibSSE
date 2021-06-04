#pragma once

#include "RE/B/BGSActorEvent.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	struct BGSFootstepEvent : public BGSActorEvent
	{
	public:
		// members
		std::uint32_t pad04;  // 04
		BSFixedString tag;    // 08
	};
	static_assert(sizeof(BGSFootstepEvent) == 0x10);
}
