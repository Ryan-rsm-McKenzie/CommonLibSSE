#include "RE/C/ChestsLooted.h"

namespace RE
{
	BSTEventSource<ChestsLooted::Event>* ChestsLooted::GetEventSource()
	{
		using func_t = decltype(&ChestsLooted::GetEventSource);
		REL::Relocation<func_t> func{ REL::ID(50257) };
		return func();
	}

	void ChestsLooted::SendEvent()
	{
		const Event e{};
		auto		source = GetEventSource();
		if (source) {
			source->SendEvent(&e);
		}
	}
}
