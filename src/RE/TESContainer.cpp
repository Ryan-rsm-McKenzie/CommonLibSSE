#include "RE/TESContainer.h"

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	bool TESContainer::GetContainerItemAt(UInt32 a_idx, Entry*& a_entry) const
	{
		if (a_idx < numEntries) {
			a_entry = entries[a_idx];
			return true;
		} else {
			return false;
		}
	}


	UInt32 TESContainer::CountItem(TESForm* a_item) const
	{
		UInt32 count = 0;
		ForEach([&](Entry* a_entry)
		{
			if (a_entry->form == a_item) {
				count += a_entry->count;
			}
			return true;
		});
		return count;
	}


	bool TESContainer::GetContainerLevItemAt(UInt32 a_idx, TESContainer::Entry*& a_entry) const
	{
		UInt32 n = 0;

		for (UInt32 i = 0; i < numEntries; ++i) {
			Entry* p = entries[i];
			if (p->form->Is(FormType::LeveledItem)) {
				if (n == a_idx) {
					a_entry = p;
					return true;
				}
				++n;
			}
		}

		return false;
	}
}
