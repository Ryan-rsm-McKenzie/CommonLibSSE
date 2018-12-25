#include "RE/Condition.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	bool Condition::Node::Run(Solution& a_solution)
	{
		typedef bool _Run_t(Node* a_this, Solution& a_visitor);
		RelocAddr<_Run_t*> _Run(CONDITION_NODE_RUN);
		return _Run(this, a_solution);
	}


	bool Condition::Match(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target)
	{
		typedef bool _Match_t(Condition* a_this, TESObjectREFR* a_perkOwner, TESObjectREFR* a_target);
		RelocAddr<_Match_t*> _Match(CONDITION_MATCH);
		return _Match(this, a_perkOwner, a_target);
	}
}
