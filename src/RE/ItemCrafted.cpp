#include "RE/ItemCrafted.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	BSTEventSource<ItemCrafted::Event>* ItemCrafted::GetEventSource()
	{
		typedef BSTEventSource<ItemCrafted::Event>* _GetEventSource_t();
		static RelocAddr<_GetEventSource_t*> _GetEventSource(ITEM_CRAFTED_GET_EVENT_SOURCE);
		return _GetEventSource();
	}
}
