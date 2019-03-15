#include "RE/InventoryMenu.h"

#include "RE/Offsets.h"


namespace RE
{
	InventoryMenu::InventoryData::Item* InventoryMenu::InventoryData::GetSelectedItem()
	{
		using func_t = function_type_t<decltype(&InventoryMenu::InventoryData::GetSelectedItem)>;
		RelocUnrestricted<func_t*> func(Offset::InventoryMenu::InventoryData::GetSelectedItem);
		return func(this);
	}


	void InventoryMenu::InventoryData::Update(TESObjectREFR* a_owner)
	{
		using func_t = function_type_t<decltype(&InventoryMenu::InventoryData::Update)>;
		RelocUnrestricted<func_t*> func(Offset::InventoryMenu::InventoryData::Update);
		return func(this, a_owner);
	}
}
