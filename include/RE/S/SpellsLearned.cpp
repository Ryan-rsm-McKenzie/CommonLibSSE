#include "RE/S/SpellsLearned.h"

namespace RE
{
	BSTEventSource<SpellsLearned::Event>* SpellsLearned::GetEventSource()
	{
		using func_t = decltype(&SpellsLearned::GetEventSource);
		REL::Relocation<func_t> func{ REL::ID(37917) };
		return func();
	}

	void SpellsLearned::SendEvent(SpellItem* a_spell)
	{
		Event e = { a_spell };
		auto  source = GetEventSource();
		if (source) {
			source->SendEvent(std::addressof(e));
		}
	}
}
