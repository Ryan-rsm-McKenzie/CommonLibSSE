#include "RE/Inventory.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTEventSource<Inventory::Event>* Inventory::GetEventSource()
	{
		using func_t = decltype(&Inventory::GetEventSource);
		REL::Offset<func_t> func(Offset::Inventory::GetEventSource);
		return func();
	}
}
