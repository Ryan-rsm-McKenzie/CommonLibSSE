#pragma once

#include "RE/C/CombatInventoryItemMagic.h"

namespace RE
{
	class CombatInventoryItemScroll : public CombatInventoryItemMagic
	{
	public:
		~CombatInventoryItemScroll() override;  // 00

		// override (CombatInventoryItemMagic)
		COMBAT_INVENTORY_ITEM GetType() override;                               // 09 - { return 8; }
		bool                  Unk_0E(CombatController* a_controller) override;  // 0E
	};
	static_assert(sizeof(CombatInventoryItemScroll) == 0x50);
}
