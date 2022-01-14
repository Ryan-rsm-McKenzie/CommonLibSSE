#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class SpellItem;

	struct SpellsLearned
	{
	public:
		struct Event
		{
		public:
			// members
			SpellItem* spell;  // 00
		};
		static_assert(sizeof(Event) == 0x8);

		static BSTEventSource<Event>* GetEventSource();
		static void                   SendEvent(SpellItem* a_spell);
	};
}
