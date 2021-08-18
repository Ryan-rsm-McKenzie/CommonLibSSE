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

		virtual ~CombatInventoryItemMagic();  // 00

		// override
		virtual void                  SaveGame(BGSSaveGameBuffer* a_buf) override;                // 03
		virtual void                  LoadGame(BGSLoadGameBuffer* a_buf) override;                // 04
		virtual float                 Unk_05() override;                                          // 05 - { return unk30; }
		virtual float                 Unk_06() override;                                          // 06 - { return unk34; }
		virtual float                 Unk_07() override;                                          // 07
		virtual float                 Unk_08() override;                                          // 08
		virtual COMBAT_INVENTORY_ITEM GetType() override;                                         // 09 - { return 4; }
		virtual std::uint32_t         Unk_0A(BGSEquipSlot a_slot) override;                       // 0A
		virtual float                 GetItemScoreMult(CombatController* a_controller) override;  // 0C
		virtual bool                  Unk_0E(CombatController* a_controller) override;            // 0E
		virtual bool                  CanCast(CombatController* a_controller) override;           // 0F - { return true; }
		virtual void                  Unk_10() override;                                          // 10
		virtual void                  Unk_11() override;                                          // 11
		virtual bool                  HasItem() override;                                         // 12 - { return unk10 && effect; }

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
