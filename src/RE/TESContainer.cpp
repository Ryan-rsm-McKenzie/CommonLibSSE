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


	UInt32 TESContainer::CountItem(TESBoundObject* a_item) const
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
}
