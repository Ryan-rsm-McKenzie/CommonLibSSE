#include "RE/Condition.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	bool Condition::Node::Run(Solution& a_solution)
	{
		using func_t = function_type_t<decltype(&Condition::Node::Run)>;
		REL::Offset<func_t*> func(Offset::Condition::Node::Run);
		return func(this, a_solution);
	}


	Condition::operator bool() const
	{
		return head != 0;
	}


	bool Condition::Run(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target)
	{
		using func_t = function_type_t<decltype(&Condition::Run)>;
		REL::Offset<func_t*> func(Offset::Condition::Run);
		return func(this, a_perkOwner, a_target);
	}
}
