#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/M/MemoryManager.h"

namespace RE
{
	class SpellItem;
	class TESLevSpell;
	class TESShout;

	class TESSpellList : BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESSpellList;

		struct SpellData  // SPLO
		{
			SpellData();
			~SpellData() = default;

			bool                         AddLevSpell(TESLevSpell* a_spell);
			bool                         AddShout(TESShout* a_spell);
			bool                         AddSpell(SpellItem* a_spell);
			std::optional<std::uint32_t> GetIndex(SpellItem* a_spell);
			std::optional<std::uint32_t> GetIndex(TESLevSpell* a_spell);
			std::optional<std::uint32_t> GetIndex(TESShout* a_spell);
			bool                         RemoveSpell(SpellItem* a_spell);

			TES_HEAP_REDEFINE_NEW();

			SpellItem**   spells;        // 00
			TESLevSpell** levSpells;     // 08
			TESShout**    shouts;        // 10
			std::uint32_t numSpells;     // 18
			std::uint32_t numlevSpells;  // 1C
			std::uint32_t numShouts;     // 20
			std::uint32_t pad24;         // 24
		};
		static_assert(sizeof(SpellData) == 0x28);

		~TESSpellList() override;  // 00

		// override (BaseFormComponent)
		void InitializeDataComponent() override;                // 01 - { return; }
		void ClearDataComponent() override;                     // 02
		void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		SpellData* actorEffects;  // 08 - SPLO
	};
	static_assert(sizeof(TESSpellList) == 0x10);
}
