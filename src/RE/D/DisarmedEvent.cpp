#include "RE/D/DisarmedEvent.h"

namespace RE
{
	BSTEventSource<DisarmedEvent::Event>* DisarmedEvent::GetEventSource()
	{
		using func_t = decltype(&DisarmedEvent::GetEventSource);
		REL::Relocation<func_t> func{ REL::ID(37392) };
		return func();
	}
}
