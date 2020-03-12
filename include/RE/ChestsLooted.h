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
			UInt8 pad0;	 // 0
		};
		STATIC_ASSERT(sizeof(Event) == 0x1);


		static BSTEventSource<Event>* GetEventSource();
		static void					  SendEvent();
	};
}
