#include "RE/I/ItemsPickpocketed.h"

namespace RE
{
	BSTEventSource<ItemsPickpocketed::Event>* ItemsPickpocketed::GetEventSource()
	{
		using func_t = decltype(&ItemsPickpocketed::GetEventSource);
		REL::Relocation<func_t> func{ Offset::ItemsPickpocketed::GetEventSource };
		return func();
	}

	void ItemsPickpocketed::SendEvent(std::int32_t a_numItems)
	{
		Event e = { a_numItems, 0 };
		auto  source = GetEventSource();
		if (source) {
			source->SendEvent(std::addressof(e));
		}
	}
}
