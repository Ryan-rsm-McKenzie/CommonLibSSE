#include "RE/TESContainer.h"

#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	auto TESContainer::GetContainerItemAt(UInt32 a_idx) const
		-> std::optional<Entry*>
	{
		if (a_idx < numEntries) {
			return std::make_optional(entries[a_idx]);
		} else {
			return std::nullopt;
		}
	}


	SInt32 TESContainer::CountItem(TESBoundObject* a_item) const
	{
		SInt32 count = 0;
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
