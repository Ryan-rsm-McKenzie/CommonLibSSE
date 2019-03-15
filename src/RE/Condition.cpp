#include "RE/Condition.h"

#include "RE/Offsets.h"


namespace RE
{
	bool Condition::Node::Run(Solution& a_solution)
	{
		using func_t = function_type_t<decltype(&Condition::Node::Run)>;
		RelocUnrestricted<func_t*> func(Offset::Condition::Node::Run);
		return func(this, a_solution);
	}


	bool Condition::Run(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target)
	{
		using func_t = function_type_t<decltype(&Condition::Run)>;
		RelocUnrestricted<func_t*> func(Offset::Condition::Run);
		return func(this, a_perkOwner, a_target);
	}
}
