#pragma once

#include "RE/C/CombatInventoryItemMagic.h"

namespace RE
{
	class CombatInventoryItemStaff : public CombatInventoryItemMagic
	{
	public:
		virtual ~CombatInventoryItemStaff();  // 00

		virtual COMBAT_INVENTORY_ITEM GetType() override;       // 09 - { return 6; }
		virtual MagicItem*            GetMagicItem() override;  // 16
	};
	static_assert(sizeof(CombatInventoryItemStaff) == 0x50);
}
