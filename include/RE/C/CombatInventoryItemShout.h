#pragma once

#include "RE/C/CombatInventoryItemMagic.h"

namespace RE
{
	class CombatInventoryItemShout : public CombatInventoryItemMagic
	{
	public:
		virtual ~CombatInventoryItemShout();  // 00

		virtual COMBAT_INVENTORY_ITEM GetType() override;                                // 09 - { return 5; }
		virtual bool                  Unk_0E(CombatController* a_controller) override;   // 0E - { return actor->GetVoiceState() != 0; }
		virtual bool                  CanCast(CombatController* a_controller) override;  // 0F - { return fCombatInventoryShoutMaxRecoveryTime >= actor->GetVoiceRecoveryTime(); }
		virtual MagicItem*            GetMagicItem() override;                           // 16
	};
	static_assert(sizeof(CombatInventoryItemShout) == 0x50);
}
