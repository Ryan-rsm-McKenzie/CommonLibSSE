#include "RE/FormComponents/TESLeveledList.h"

#include "RE/FormComponents/Components/FormTraits.h"

namespace RE
{
	std::set<TESForm*> TESLeveledList::GetContainedForms() const
	{
		std::set<TESForm*> results;
		std::stack<const TESLeveledList*> queued;
		queued.push(this);
		do {
			auto iter = queued.top();
			queued.pop();
			for (const auto& entry : iter->entries) {
				auto form = entry.form;
				if (form) {
					auto ll = form->As<TESLeveledList>();
					if (ll) {
						queued.push(ll);
					} else {
						results.insert(form);
					}
				}
			}
		} while (!queued.empty());
		return results;
	}
}
