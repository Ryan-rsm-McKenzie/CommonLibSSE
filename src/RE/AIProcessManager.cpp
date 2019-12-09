#include "RE/AIProcessManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	AIProcessManager* AIProcessManager::GetSingleton()
	{
		REL::Offset<AIProcessManager**> singleton(Offset::AIProcessManager::Singleton);
		return *singleton;
	}


	void AIProcessManager::SetCombatAlarmState(Actor* a_actor, bool a_enabled)
	{
		using func_t = function_type_t<decltype(&AIProcessManager::SetCombatAlarmState)>;
		REL::Offset<func_t*> func(Offset::AIProcessManager::SetCombatAlarmState);
		return func(this, a_actor, a_enabled);
	}
}
