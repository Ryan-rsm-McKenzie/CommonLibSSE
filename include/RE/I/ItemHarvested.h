#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESBoundObject;
	class Actor;

	struct TESHarvestedEvent
	{
	public:
		struct ItemHarvested
		{
		public:
			// members
			TESBoundObject* produceItem;  // 00
			Actor*          harvester;    // 08
		};
		static_assert(sizeof(ItemHarvested) == 0x10);

		static BSTEventSource<TESHarvestedEvent::ItemHarvested>* GetEventSource();
	};
}
