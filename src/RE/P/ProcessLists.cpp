#include "RE/P/ProcessLists.h"

namespace RE
{
	ProcessLists* ProcessLists::GetSingleton()
	{
		REL::Relocation<ProcessLists**> singleton{ REL::Offset(0x1F592D0) };
		return *singleton;
	}

	void ProcessLists::ClearCachedFactionFightReactions() const
	{
		using func_t = decltype(&ProcessLists::ClearCachedFactionFightReactions);
		REL::Relocation<func_t> func{ REL::Offset(0x7076A0) };
		return func(this);
	}

	void ProcessLists::StopCombatAndAlarmOnActor(Actor* a_actor, bool a_notAlarm)
	{
		using func_t = decltype(&ProcessLists::StopCombatAndAlarmOnActor);
		REL::Relocation<func_t> func{ REL::Offset(0x702060) };
		return func(this, a_actor, a_notAlarm);
	}
}
