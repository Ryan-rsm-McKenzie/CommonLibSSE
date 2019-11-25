#pragma once

#include "RE/BSTEvent.h"


namespace RE
{
	struct ChestsLooted
	{
	public:
		struct Event
		{
		public:
			UInt64 pad0;	// 0
		};
		STATIC_ASSERT(sizeof(Event) == 0x8);


		static BSTEventSource<Event>*	GetEventSource();
		static void						SendEvent();
	};
}
