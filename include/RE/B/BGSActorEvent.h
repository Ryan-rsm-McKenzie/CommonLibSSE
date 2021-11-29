#pragma once

#include "RE/B/BSPointerHandle.h"

namespace RE
{
	struct BGSActorEvent
	{
	public:
		// members
		ActorHandle actor;  // 0
	};
	static_assert(sizeof(BGSActorEvent) == 0x4);
}
