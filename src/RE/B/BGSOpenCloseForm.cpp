#include "RE/B/BGSOpenCloseForm.h"

namespace RE
{
	auto BGSOpenCloseForm::GetOpenState(const TESObjectREFR* a_ref)
		-> OPEN_STATE
	{
		using func_t = decltype(&BGSOpenCloseForm::GetOpenState);
		REL::Relocation<func_t> func{ REL::ID(14288) };
		return func(a_ref);
	}

	void BGSOpenCloseForm::SetOpenState(TESObjectREFR* a_ref, bool a_open, bool a_snap)
	{
		using func_t = decltype(&BGSOpenCloseForm::SetOpenState);
		REL::Relocation<func_t> func{ REL::ID(14287) };
		return func(a_ref, a_open, a_snap);
	}
}
