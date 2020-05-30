#include "RE/Inventory.h"


namespace RE
{
	BSTEventSource<Inventory::Event>* Inventory::GetEventSource()
	{
		using func_t = decltype(&Inventory::GetEventSource);
		REL::Offset<func_t> func(Offset::Inventory::GetEventSource);
		return func();
	}
}
