#include "RE/ScriptEventSourceHolder.h"

#include "skse64_common/Relocation.h"  // RelocAddr
#include "skse64/GameEvents.h"  // GetEventDispatcherList()

#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"  // TESObjectREFRPtr


namespace RE
{
	ScriptEventSourceHolder* ScriptEventSourceHolder::GetSingleton()
	{
		typedef ScriptEventSourceHolder* _GetEventSourceList_t();
		static _GetEventSourceList_t* _GetEventSourceList = reinterpret_cast<_GetEventSourceList_t*>(::GetEventDispatcherList.GetUIntPtr());
		return _GetEventSourceList();
	}


	void ScriptEventSourceHolder::SendActivateEvent(TESObjectREFRPtr& a_target, TESObjectREFRPtr& a_caster)
	{
		typedef void _SendActivateEvent_t(ScriptEventSourceHolder* a_this, TESObjectREFRPtr& a_target, TESObjectREFRPtr& a_caster);
		RelocAddr<_SendActivateEvent_t*> _SendActivateEvent(SCRIPT_EVENT_SOURCE_HOLDER_SEND_ACTIVATE_EVENT);
		_SendActivateEvent(this, a_target, a_caster);
	}
}
