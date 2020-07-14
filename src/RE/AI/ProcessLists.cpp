#include "RE/AI/ProcessLists.h"


namespace RE
{
	ProcessLists* ProcessLists::GetSingleton()
	{
		REL::Offset<ProcessLists**> singleton = REL::ID(514167);
		return *singleton;
	}


	void ProcessLists::ClearCachedFactionFightReactions() const
	{
		using func_t = decltype(&ProcessLists::ClearCachedFactionFightReactions);
		REL::Offset<func_t> func = REL::ID(40396);
		return func(this);
	}


	void ProcessLists::StopCombatAndAlarmOnActor(Actor* a_actor, bool a_notAlarm)
	{
		using func_t = decltype(&ProcessLists::StopCombatAndAlarmOnActor);
		REL::Offset<func_t> func = REL::ID(40330);
		return func(this, a_actor, a_notAlarm);
	}
}
