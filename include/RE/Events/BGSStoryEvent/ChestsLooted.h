#pragma once

#include "RE/BSCore/BSTEvent.h"


namespace RE
{
	struct ChestsLooted
	{
	public:
		struct Event
		{
		public:
			std::uint8_t pad0;	// 0
		};
		static_assert(sizeof(Event) == 0x1);


		static BSTEventSource<Event>* GetEventSource();
		static void					  SendEvent();
	};
}
