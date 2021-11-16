#include "RE/S/ScriptEventSourceHolder.h"

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	ScriptEventSourceHolder* ScriptEventSourceHolder::GetSingleton()
	{
		using func_t = decltype(&ScriptEventSourceHolder::GetSingleton);
		REL::Relocation<func_t> func{ REL::Offset(0x1941C0) };
		return func();
	}

#if 0
	void ScriptEventSourceHolder::SendActivateEvent(const NiPointer<TESObjectREFR>& a_objectActivated, const NiPointer<TESObjectREFR>& a_actionRef)
	{
		using func_t = decltype(&ScriptEventSourceHolder::SendActivateEvent);
		REL::Relocation<func_t> func{ REL::Offset(0x0) };
		return func(this, a_objectActivated, a_actionRef);
	}
#endif

	void ScriptEventSourceHolder::SendOpenCloseEvent(const NiPointer<TESObjectREFR>& a_ref, const NiPointer<TESObjectREFR>& a_activeRef, bool a_isOpened)
	{
		using func_t = decltype(&ScriptEventSourceHolder::SendOpenCloseEvent);
		REL::Relocation<func_t> func{ REL::Offset(0x194250) };
		return func(this, a_ref, a_activeRef, a_isOpened);
	}
}
