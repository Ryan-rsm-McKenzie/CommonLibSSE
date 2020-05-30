#pragma once

#include "RE/BSPointerHandle.h"


namespace RE
{
	struct BGSActorEvent
	{
	public:
		// members
		ActorHandle actor;	// 0
	};
	STATIC_ASSERT(sizeof(BGSActorEvent) == 0x4);
}
