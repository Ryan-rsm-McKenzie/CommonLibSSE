#include "RE/S/SkillIncrease.h"

namespace RE
{
	BSTEventSource<SkillIncrease::Event>* SkillIncrease::GetEventSource()
	{
		using func_t = decltype(&SkillIncrease::GetEventSource);
		REL::Relocation<func_t> func{ REL::Offset(0x6BCC80) };
		return func();
	}
}
