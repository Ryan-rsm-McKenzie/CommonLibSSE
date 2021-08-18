#pragma once

#include "RE/C/CombatObject.h"

namespace RE
{
	class CombatInventoryItem;
	class MagicItem;

	class CombatMagicCaster : public CombatObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatMagicCaster;

		~CombatMagicCaster() override;  // 00

		// override (CombatObject)
		void SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04

		// add
		virtual void Unk_05() = 0;  // 05
		virtual void Unk_06();      // 06
		virtual void Unk_07();      // 07
		virtual void Unk_08();      // 08
		virtual void Unk_09();      // 09
		virtual void Unk_0A();      // 0A
		virtual void Unk_0B();      // 0B
		virtual void Unk_0C();      // 0C
		virtual void Unk_0D();      // 0D

		// members
		CombatInventoryItemMagic* inventoryItem;  // 10
		MagicItem*                magicItem;      // 18
	};
	static_assert(sizeof(CombatMagicCaster) == 0x20);
}
