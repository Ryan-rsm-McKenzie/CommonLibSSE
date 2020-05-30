#pragma once

#include "RE/BSTEvent.h"


namespace RE
{
	struct ItemsPickpocketed
	{
	public:
		struct Event
		{
		public:
			// members
			SInt32 numItems;  // 0
			UInt32 pad4;	  // 4
		};
		STATIC_ASSERT(sizeof(Event) == 0x8);


		static BSTEventSource<Event>* GetEventSource();
		static void					  SendEvent(SInt32 a_numItems);
	};
}
