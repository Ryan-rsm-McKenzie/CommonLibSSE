#pragma once

#include "RE/BSTEvent.h"  // BSTEventSource


namespace RE
{
	struct ItemsPickpocketed
	{
	public:
		struct Event
		{
		public:
			UInt32 numItems;	// 0
			UInt32 pad4;		// 4
		};
		STATIC_ASSERT(sizeof(Event) == 0x8);


		static BSTEventSource<Event>*	GetEventSource();
		static void						SendEvent(UInt32 a_numItems);
	};
}
