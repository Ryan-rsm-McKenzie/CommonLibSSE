#pragma once

#include "RE/C/CombatInventoryItemMagic.h"

namespace RE
{
	class CombatInventoryItemScroll : public CombatInventoryItemMagic
	{
	public:
		virtual ~CombatInventoryItemScroll();  // 00

		virtual COMBAT_INVENTORY_ITEM GetType() override;                               // 09 - { return 8; }
		virtual bool                  Unk_0E(CombatController* a_controller) override;  // 0E
	};
	static_assert(sizeof(CombatInventoryItemScroll) == 0x50);
}
