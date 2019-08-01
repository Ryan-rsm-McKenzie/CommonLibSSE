#include "RE/ItemList.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	auto ItemList::GetSelectedItem()
		-> Item*
	{
		if (unk50) {
			return 0;
		}

		GFxValue selectedIndex;
		auto success = root.GetMember("selectedIndex", &selectedIndex);
		if (!success || !selectedIndex.IsNumber()) {
			return 0;
		}

		auto idx = static_cast<SInt32>(selectedIndex.GetNumber());
		if (idx < 0 || idx >= items.size()) {
			return 0;
		}

		return items[idx];
	}


	void ItemList::Update(TESObjectREFR* a_owner)
	{
		using func_t = function_type_t<decltype(&ItemList::Update)>;
		REL::Offset<func_t*> func(Offset::ItemList::Update);
		return func(this, a_owner);
	}
}
