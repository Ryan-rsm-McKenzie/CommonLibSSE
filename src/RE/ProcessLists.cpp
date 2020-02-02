#include "RE/ProcessLists.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ProcessLists* ProcessLists::GetSingleton()
	{
		REL::Offset<ProcessLists**> singleton(Offset::ProcessLists::Singleton);
		return *singleton;
	}


	void ProcessLists::StopCombatAndAlarmOnActor(Actor* a_actor, bool a_dontEndAlarm)
	{
		using func_t = decltype(&ProcessLists::StopCombatAndAlarmOnActor);
		REL::Offset<func_t> func(Offset::ProcessLists::StopCombatAndAlarmOnActor);
		return func(this, a_actor, a_dontEndAlarm);
	}
}
