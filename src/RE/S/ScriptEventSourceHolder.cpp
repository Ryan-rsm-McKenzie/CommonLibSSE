#include "RE/S/ScriptEventSourceHolder.h"

#include "RE/T/TESActivateEvent.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	ScriptEventSourceHolder* ScriptEventSourceHolder::GetSingleton()
	{
		using func_t = decltype(&ScriptEventSourceHolder::GetSingleton);
		REL::Relocation<func_t> func{ REL::ID(14298) };
		return func();
	}

	void ScriptEventSourceHolder::SendActivateEvent(const NiPointer<TESObjectREFR>& a_objectActivated, const NiPointer<TESObjectREFR>& a_actionRef)
	{
		const TESActivateEvent e{
			a_objectActivated,
			a_actionRef
		};

		this->SendEvent(&e);
	}

	void ScriptEventSourceHolder::SendOpenCloseEvent(const NiPointer<TESObjectREFR>& a_ref, const NiPointer<TESObjectREFR>& a_activeRef, bool a_isOpened)
	{
		using func_t = decltype(&ScriptEventSourceHolder::SendOpenCloseEvent);
		REL::Relocation<func_t> func{ REL::ID(14299) };
		return func(this, a_ref, a_activeRef, a_isOpened);
	}
}
