#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	struct ItemsPickpocketed
	{
	public:
		struct Event
		{
		public:
			// members
			std::int32_t  numItems;  // 0
			std::uint32_t pad4;      // 4
		};
		static_assert(sizeof(Event) == 0x8);

		static BSTEventSource<Event>* GetEventSource();
		static void                   SendEvent(std::int32_t a_numItems);
	};
}
