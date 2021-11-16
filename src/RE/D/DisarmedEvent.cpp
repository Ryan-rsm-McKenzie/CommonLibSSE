#include "RE/D/DisarmedEvent.h"

namespace RE
{
	BSTEventSource<DisarmedEvent::Event>* DisarmedEvent::GetEventSource()
	{
		using func_t = decltype(&DisarmedEvent::GetEventSource);
		REL::Relocation<func_t> func{ REL::Offset(0x642230) };
		return func();
	}
}
