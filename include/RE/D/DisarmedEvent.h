#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class Actor;

	struct DisarmedEvent
	{
	public:
		struct Event
		{
		public:
			// members
			Actor* source;  // 00
			Actor* target;  // 08
		};
		static_assert(sizeof(Event) == 0x10);

		static BSTEventSource<DisarmedEvent::Event>* GetEventSource();
	};
}
