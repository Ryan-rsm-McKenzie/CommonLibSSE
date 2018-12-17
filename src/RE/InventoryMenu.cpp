#include "RE/InventoryMenu.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	StandardItemData* InventoryMenu::InventoryData::GetSelectedItemData()
	{
		typedef StandardItemData* _GetSelectedItemData_t(InventoryData* a_this);
		RelocAddr<_GetSelectedItemData_t*> _GetSelectedItemData(INVENTORY_MENU_INVENTORY_DATA_GET_SELECTED_ITEM_DATA);
		return _GetSelectedItemData(this);
	}


	void InventoryMenu::InventoryData::Update(TESObjectREFR* a_owner)
	{
		typedef void _Update_t(InventoryData* a_this, TESObjectREFR* a_owner);
		RelocAddr<_Update_t*> _Update(INVENTORY_MENU_INVENTORY_DATA_UPDATE);
		_Update(this, a_owner);
	}
}
