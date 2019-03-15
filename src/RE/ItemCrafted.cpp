#include "RE/ItemCrafted.h"

#include "RE/Offsets.h"


namespace RE
{
	BSTEventSource<ItemCrafted::Event>* ItemCrafted::GetEventSource()
	{
		using func_t = function_type_t<decltype(&ItemCrafted::GetEventSource)>;
		RelocUnrestricted<func_t*> func(Offset::ItemCrafted::GetEventSource);
		return func();
	}
}
