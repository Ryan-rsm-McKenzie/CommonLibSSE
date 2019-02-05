#include "RE/Inventory.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/BSTEvent.h"  // BSTEventSource
#include "RE/Offsets.h"


namespace RE
{
	BSTEventSource<Inventory::Event>* Inventory::GetEventSource()
	{
		typedef BSTEventSource<Inventory::Event>* _GetEventSource_t();
		static RelocAddr<_GetEventSource_t*> _GetEventSource(INVENTORY_GET_EVENT_SOURCE);
		return _GetEventSource();
	}
}
