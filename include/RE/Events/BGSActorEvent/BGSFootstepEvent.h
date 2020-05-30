#pragma once

#include "RE/Events/BGSActorEvent/BGSActorEvent.h"
#include "RE/BSCore/BSFixedString.h"


namespace RE
{
	struct BGSFootstepEvent : public BGSActorEvent
	{
	public:
		// members
		UInt32		  pad04;  // 04
		BSFixedString tag;	  // 08
	};
	STATIC_ASSERT(sizeof(BGSFootstepEvent) == 0x10);
}
