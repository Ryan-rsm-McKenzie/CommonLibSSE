#include "RE/A/ActorKill.h"

namespace RE
{
	BSTEventSource<ActorKill::Event>* ActorKill::GetEventSource()
	{
		using func_t = decltype(&ActorKill::GetEventSource);
		REL::Relocation<func_t> func{ REL::Offset(0x642050) };
		return func();
	}
}
