#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class Actor;

	struct SoulsTrapped
	{
	public:
		struct Event
		{
		public:
			// members
			Actor* trapper;  // 00
			Actor* target;   // 08
		};
		static_assert(sizeof(Event) == 0x10);

		static BSTEventSource<SoulsTrapped::Event>* GetEventSource();
		static void                                 SendEvent(Actor* a_trapper, Actor* a_target);
	};
}
