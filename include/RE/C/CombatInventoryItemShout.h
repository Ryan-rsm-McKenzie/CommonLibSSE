#pragma once

#include "RE/C/CombatInventoryItemMagic.h"

namespace RE
{
	class CombatInventoryItemShout : public CombatInventoryItemMagic
	{
	public:
		~CombatInventoryItemShout() override;  // 00

		// override (CombatInventoryItemMagic)
		COMBAT_INVENTORY_ITEM GetType() override;                                         // 09 - { return 5; }
		bool                  Unk_0E(CombatController* a_controller) override;            // 0E - { return actor->GetVoiceState() != 0; }
		bool                  CheckShouldEquip(CombatController* a_controller) override;  // 0F - { return fCombatInventoryShoutMaxRecoveryTime >= actor->GetVoiceRecoveryTime(); }
		MagicItem*            GetMagicItem() override;                                    // 16
	};
	static_assert(sizeof(CombatInventoryItemShout) == 0x50);
}
