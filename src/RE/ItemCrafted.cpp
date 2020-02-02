#include "RE/ItemCrafted.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTEventSource<ItemCrafted::Event>* ItemCrafted::GetEventSource()
	{
		using func_t = decltype(&ItemCrafted::GetEventSource);
		REL::Offset<func_t> func(Offset::ItemCrafted::GetEventSource);
		return func();
	}
}
