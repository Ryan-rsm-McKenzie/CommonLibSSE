#pragma once

#include "RE/C/CombatObject.h"

namespace RE
{
	class BGSLoadGameBuffer;
	class BGSSaveGameBuffer;
	class CombatController;
	class TESBoundObject;
	class BGSEquipSlot;

	enum class COMBAT_INVENTORY_ITEM
	{
		kNone = 0,
		kMelee = 1,
		kRanged = 2,
		kShield = 3,
		kOneHandedBlock = kShield,
		kMagic = 4,
		kShout = 5,
		kStaff = 6,
		kPotion = 7,
		kScroll = 8,
		kTorch = 9
	};

	class CombatInventoryItem : public CombatObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatInventoryItem;

		~CombatInventoryItem() override;  // 00

		// override (CombatObject)
		void SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04

		// add
		virtual float                 Unk_05();                                              // 05 - { return 0.0; }
		virtual float                 Unk_06();                                              // 06 - { return 0.0; }
		virtual float                 Unk_07();                                              // 07 - { return 0.0; }
		virtual float                 Unk_08();                                              // 08 - { return FLT_MAX; }
		virtual COMBAT_INVENTORY_ITEM GetType();                                             // 09
		virtual std::uint32_t         Unk_0A(BGSEquipSlot a_slot);                           // 0A - { return Unk_09(); }
		virtual void                  Unk_0B() = 0;                                          // 0B
		virtual float                 GetItemScoreMult(CombatController* a_controller) = 0;  // 0C
		virtual CombatInventoryItem*  CreateClone() = 0;                                     // 0D
		virtual bool                  Unk_0E(CombatController* a_controller);                // 0E
		virtual bool                  CheckShouldEquip(CombatController* a_controller);      // 0F - { return !data08->combatFleeing; }
		virtual void                  Unk_10();                                              // 10
		virtual void                  Unk_11();                                              // 11
		virtual void                  Unk_12();                                              // 12
		virtual bool                  HasItem();                                             // 13 - { return unk10 != nullptr; }
		virtual void                  Unk_14();                                              // 14

		// members
		TESBoundObject* item;            // 10
		float           equipmentScore;  // 18
		std::uint32_t   unk1C;           // 1C
		BGSEquipSlot*   equipSlot;       // 20
		std::uint32_t   unk28;           // 28
		std::uint32_t   unk2C;           // 2C
	};
	static_assert(sizeof(CombatInventoryItem) == 0x30);
}
