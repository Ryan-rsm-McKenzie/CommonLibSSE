#include "RE/S/SkillIncrease.h"

namespace RE
{
	BSTEventSource<SkillIncrease::Event>* SkillIncrease::GetEventSource()
	{
		using func_t = decltype(&SkillIncrease::GetEventSource);
		REL::Relocation<func_t> func{ REL::ID(39248) };
		return func();
	}
}
