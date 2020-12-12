#include "RE/T/TESLeveledList.h"

#include "RE/F/FormTraits.h"

namespace RE
{
	std::vector<TESForm*> TESLeveledList::GetContainedForms() const
	{
		std::vector<TESForm*>			  results;
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
						results.push_back(form);
					}
				}
			}
		} while (!queued.empty());
		return results;
	}
}
