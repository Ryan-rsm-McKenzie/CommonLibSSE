#include "RE/BGSEntryPointPerkEntry.h"


namespace RE
{
	UInt32 BGSEntryPointPerkEntry::Conditions::GetNumConditions()
	{
		uintptr_t start = (uintptr_t)(this);
		constexpr uintptr_t backTrack = sizeof(void*);
		return *(UInt32*)(start - backTrack);
	}


	bool BGSEntryPointPerkEntry::Conditions::Run(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target)
	{
		UInt32 numConditions = GetNumConditions();
		Condition* conditions = &_conditionsHead;
		bool result = false;
		for (UInt32 i = 0; i < numConditions; ++i) {
			if (i == 0) {
				result = conditions[i].Match(a_perkOwner, a_target);
			} else {
				result = conditions[i].Match(a_target, a_perkOwner);
			}
			if (!result) {
				break;
			}
		}
		return result;
	}


	bool BGSEntryPointPerkEntry::HasType(EntryPointType a_type)
	{
		return type == a_type;
	}
}
