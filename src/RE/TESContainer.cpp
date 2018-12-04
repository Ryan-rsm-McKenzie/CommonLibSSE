#include "RE/TESContainer.h"

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class ItemCounter
	{
	public:
		constexpr ItemCounter(TESForm* a_item) :
			_count(0),
			_item(a_item)
		{}


		bool Accept(TESContainer::Entry* a_entry)
		{
			if (a_entry->form == _item) {
				_count += a_entry->count;
			}
			return true;
		}


		constexpr UInt32 Count() const
		{
			return _count;
		}

	private:
		UInt32		_count;
		TESForm*	_item;
	};


	bool TESContainer::GetContainerItemAt(UInt32 idx, Entry*& entry) const
	{
		if (idx < numEntries) {
			entry = entries[idx];
			return true;
		} else {
			return false;
		}
	}


	UInt32 TESContainer::CountItem(TESForm * item) const
	{
		ItemCounter v(item);
		Visit(v);
		return v.Count();
	}


	bool TESContainer::GetContainerLevItemAt(UInt32 idx, TESContainer::Entry *& entry) const
	{
		UInt32 n = 0;

		for (UInt32 i = 0; i < numEntries; ++i) {
			Entry *p = entries[i];
			if (p->form->Is(FormType::LeveledItem)) {
				if (n == idx) {
					entry = p;
					return true;
				}
				++n;
			}
		}

		return false;
	}
}
