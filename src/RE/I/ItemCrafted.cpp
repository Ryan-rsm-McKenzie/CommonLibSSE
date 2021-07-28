#include "RE/I/ItemCrafted.h"

namespace RE
{
	BSTEventSource<ItemCrafted::Event>* ItemCrafted::GetEventSource()
	{
		using func_t = decltype(&ItemCrafted::GetEventSource);
		REL::Relocation<func_t> func{ Offset::ItemCrafted::GetEventSource };
		return func();
	}
}
