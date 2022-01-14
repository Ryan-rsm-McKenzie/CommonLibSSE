#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class MapMarkerData;

	struct LocationDiscovery
	{
	public:
		struct Event
		{
		public:
			// members
			MapMarkerData* mapMarkerData;  // 00
			const char*    worldspaceID;   // 08
		};
		static_assert(sizeof(Event) == 0x10);

		static BSTEventSource<LocationDiscovery::Event>* GetEventSource();
	};
}
