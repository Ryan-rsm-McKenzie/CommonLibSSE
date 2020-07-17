#include "RE/FormComponents/TESLeveledList.h"

#include "RE/FormComponents/Components/FormTraits.h"

namespace RE
{
	std::set<TESForm*> TESLeveledList::GetContainedForms() const
	{
		std::set<TESForm*> results;
		for (const auto& entry : entries) {
			auto form = entry.form;
			if (form) {
				auto ll = form->As<TESLeveledList>();
				if (ll) {
					results.merge(ll->GetContainedForms());
				} else {
					results.insert(form);
				}
			}
		}
		return results;
	}
}
