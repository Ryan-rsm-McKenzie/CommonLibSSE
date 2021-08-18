#pragma once

#include "RE/C/CombatInventoryItemMagic.h"

namespace RE
{
	class CombatInventoryItemPotion : public CombatInventoryItemMagic
	{
	public:
		~CombatInventoryItemPotion() override;  // 00

		// override (CombatInventoryItemMagic)
		COMBAT_INVENTORY_ITEM GetType() override;                               // 09 - { return 7; }
		bool                  Unk_0E(CombatController* a_controller) override;  // 0E
	};
	static_assert(sizeof(CombatInventoryItemPotion) == 0x50);
}
