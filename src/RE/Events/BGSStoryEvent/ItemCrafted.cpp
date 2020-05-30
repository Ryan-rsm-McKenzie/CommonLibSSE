#include "RE/Events/BGSStoryEvent/ItemCrafted.h"


namespace RE
{
	BSTEventSource<ItemCrafted::Event>* ItemCrafted::GetEventSource()
	{
		using func_t = decltype(&ItemCrafted::GetEventSource);
		REL::Offset<func_t> func(Offset::ItemCrafted::GetEventSource);
		return func();
	}
}
