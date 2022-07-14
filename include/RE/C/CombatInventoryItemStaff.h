#pragma once

#include "RE/C/CombatInventoryItemMagic.h"

namespace RE
{
	class CombatInventoryItemStaff : public CombatInventoryItemMagic
	{
	public:
		~CombatInventoryItemStaff() override;  // 00

		// override (CombatInventoryItemMagic)
		COMBAT_INVENTORY_ITEM GetType() override;       // 09 - { return 6; }
		MagicItem*            GetMagicItem() override;  // 16
	};
	static_assert(sizeof(CombatInventoryItemStaff) == 0x50);
}
