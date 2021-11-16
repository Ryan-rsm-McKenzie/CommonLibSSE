#include "RE/I/ItemHarvested.h"

namespace RE
{
	BSTEventSource<TESHarvestedEvent::ItemHarvested>* TESHarvestedEvent::GetEventSource()
	{
		using func_t = decltype(&TESHarvestedEvent::GetEventSource);
		REL::Relocation<func_t> func{ REL::Offset(0x01A8990) };
		return func();
	}
}
