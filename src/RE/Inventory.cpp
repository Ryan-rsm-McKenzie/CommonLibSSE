#include "RE/Inventory.h"

#include "RE/BSTEvent.h"  // BSTEventSource
#include "RE/Offsets.h"


namespace RE
{
	BSTEventSource<Inventory::Event>* Inventory::GetEventSource()
	{
		using func_t = function_type_t<decltype(&Inventory::GetEventSource)>;
		RelocUnrestricted<func_t*> func(Offset::Inventory::GetEventSource);
		return func();
	}
}
