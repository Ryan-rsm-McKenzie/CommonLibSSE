#pragma once

#include "RE/A/ActorValues.h"
#include "RE/B/BSTEvent.h"

namespace RE
{
	class PlayerCharacter;

	struct SkillIncrease
	{
	public:
		struct Event
		{
		public:
			// members
			PlayerCharacter* player;      // 00
			ActorValue       actorValue;  // 08
			std::uint32_t    pad0C;       // 0C
		};
		static_assert(sizeof(Event) == 0x10);

		static BSTEventSource<SkillIncrease::Event>* GetEventSource();
	};
}
