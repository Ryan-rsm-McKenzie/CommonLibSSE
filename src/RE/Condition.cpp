#include "RE/Condition.h"

#include "skse64_common/Relocation.h"  // RelocAddr
#include "skse64/GameForms.h"  // BGSPerk
#include "skse64/GameRTTI.h"  // DYNAMIC_CAST

#include <vector>  // vector

#include "RE/Offsets.h"


namespace RE
{
	bool Condition::Node::Run(Solution& a_solution)
	{
		typedef bool _Run_t(Node* a_this, Solution& a_visitor);
		RelocAddr<_Run_t*> _Run(CONDITION_NODE_RUN);
		return _Run(this, a_solution);
	}


	bool Condition::Run(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target)
	{
		TESObjectREFR* runTarget = 0;
		std::vector<bool> results;
		RunOn runOn = RunOn::kTarget;
		Node* nodeStart = 0;
		TESObjectREFR* subject = 0;
		TESObjectREFR* target = 0;
		while (runOn > RunOn::kNone) {
			switch (runOn) {
			case RunOn::kTarget:
				runOn = RunOn::kPerkOwner;
				nodeStart = targetNodes;
				subject = a_target;
				target = a_perkOwner;
				break;
			case RunOn::kPerkOwner:
				runOn = RunOn::kNone;
				nodeStart = perkOwnerNodes;
				subject = a_perkOwner;
				target = a_target;
				break;
			case RunOn::kNone:
			default:
				break;
			}

			for (Node* node = nodeStart; node; node = node->next) {
				Solution solution(subject, target);
				bool success = node->Run(solution);
				if (!node->comparisonFlags.isOR) {
					if (!success) {
						return false;
					}
				} else {
					results.emplace_back(success);
				}
			}
		}

		for (auto& result : results) {
			if (result) {
				return true;
			}
		}
		return results.empty();
	}


	bool Condition::Match(TESObjectREFR* a_perkOwner, TESObjectREFR* a_target)
	{
		typedef bool _Match_t(Condition* a_this, TESObjectREFR* a_perkOwner, TESObjectREFR* a_target);
		RelocAddr<_Match_t*> _Match(CONDITION_MATCH);
		return _Match(this, a_perkOwner, a_target);
	}
}
