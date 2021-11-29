#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESObjectREFR;
	class InventoryEntryData;

	struct Inventory
	{
	public:
		struct Event
		{
		public:
			// members
			TESObjectREFR*      objRefr;    // 00
			InventoryEntryData* entryData;  // 08
			std::int32_t        newCount;   // 10
			std::int32_t        prevCount;  // 14
		};
		static_assert(sizeof(Event) == 0x18);

		static BSTEventSource<Inventory::Event>* GetEventSource();
	};
}
