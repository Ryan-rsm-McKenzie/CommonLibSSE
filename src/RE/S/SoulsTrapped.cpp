#include "RE/S/SoulsTrapped.h"

namespace RE
{
	BSTEventSource<SoulsTrapped::Event>* SoulsTrapped::GetEventSource()
	{
		using func_t = decltype(&SoulsTrapped::GetEventSource);
		REL::Relocation<func_t> func{ REL::Offset(0x65C9E0) };
		return func();
	}

	void SoulsTrapped::SendEvent(Actor* a_trapper, Actor* a_target)
	{
		Event e = { a_trapper, a_target };
		auto  source = GetEventSource();
		if (source) {
			source->SendEvent(std::addressof(e));
		}
	}
}
