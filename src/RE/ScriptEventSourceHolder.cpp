#include "RE/ScriptEventSourceHolder.h"

#include "skse64/GameEvents.h"  // GetEventDispatcherList

#include "RE/Offsets.h"
#include "REL/Relocation.h"
#include "RE/TESObjectREFR.h"  // TESObjectREFRPtr


namespace RE
{
	ScriptEventSourceHolder* ScriptEventSourceHolder::GetSingleton()
	{
		using func_t = function_type_t<decltype(&ScriptEventSourceHolder::GetSingleton)>;
		func_t* func = reinterpret_cast<func_t*>(::GetEventDispatcherList.GetUIntPtr());
		return func();
	}


	void ScriptEventSourceHolder::SendActivateEvent(NiPointer<TESObjectREFR>& a_target, NiPointer<TESObjectREFR>& a_caster)
	{
		using func_t = function_type_t<decltype(&ScriptEventSourceHolder::SendActivateEvent)>;
		REL::Offset<func_t*> func(Offset::ScriptEventSourceHolder::SendActivateEvent);
		return func(this, a_target, a_caster);
	}
}
