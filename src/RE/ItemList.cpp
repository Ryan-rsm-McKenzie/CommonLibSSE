#include "RE/ItemList.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	auto ItemList::GetSelectedItem()
		-> Item*
	{
		using func_t = function_type_t<decltype(&ItemList::GetSelectedItem)>;
		REL::Offset<func_t*> func(Offset::ItemList::GetSelectedItem);
		return func(this);
	}


	void ItemList::Update(TESObjectREFR* a_owner)
	{
		using func_t = function_type_t<decltype(&ItemList::Update)>;
		REL::Offset<func_t*> func(Offset::ItemList::Update);
		return func(this, a_owner);
	}
}
