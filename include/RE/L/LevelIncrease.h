#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class PlayerCharacter;

	struct LevelIncrease
	{
	public:
		struct Event
		{
		public:
			// members
			PlayerCharacter* player;    // 00
			std::uint16_t    newLevel;  // 08
			std::uint16_t    pad0A;     // 0A
			std::uint32_t    pad0C;     // 0C
		};
		static_assert(sizeof(Event) == 0x10);

		static BSTEventSource<LevelIncrease::Event>* GetEventSource();
	};
}
