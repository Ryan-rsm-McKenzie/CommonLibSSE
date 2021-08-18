#pragma once

#include "RE/C/CombatInventoryItem.h"

namespace RE
{
	class MagicItem;
	struct Effect;

	class CombatInventoryItemMagic : public CombatInventoryItem
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatInventoryItemMagic;

		~CombatInventoryItemMagic() override;  // 00

		// override (CombatInventoryItem)
		void                  SaveGame(BGSSaveGameBuffer* a_buf) override;                // 03
		void                  LoadGame(BGSLoadGameBuffer* a_buf) override;                // 04
		float                 Unk_05() override;                                          // 05 - { return unk30; }
		float                 Unk_06() override;                                          // 06 - { return unk34; }
		float                 Unk_07() override;                                          // 07
		float                 Unk_08() override;                                          // 08
		COMBAT_INVENTORY_ITEM GetType() override;                                         // 09 - { return 4; }
		std::uint32_t         Unk_0A(BGSEquipSlot a_slot) override;                       // 0A
		float                 GetItemScoreMult(CombatController* a_controller) override;  // 0C
		bool                  Unk_0E(CombatController* a_controller) override;            // 0E
		bool                  CanCast(CombatController* a_controller) override;           // 0F - { return true; }
		void                  Unk_10() override;                                          // 10
		void                  Unk_11() override;                                          // 11
		bool                  HasItem() override;                                         // 12 - { return unk10 && effect; }

		//add
		virtual void       Unk_15() = 0;    // 15
		virtual MagicItem* GetMagicItem();  // 16 - { return unk10; };

		// members
		float   combatDistance;    // 30
		float   combatRange;       // 34
		float   tacticalDuration;  // 38
		float   power;             // 3C
		float   currentAV;         // 40
		Effect* effect;            // 48
	};
	static_assert(sizeof(CombatInventoryItemMagic) == 0x50);
}
