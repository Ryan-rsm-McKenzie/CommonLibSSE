#pragma once

#include "RE/B/BaseFormComponent.h"

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
			SpellItem**	  spells;		 // 00
			TESLevSpell** levSpells;	 // 08
			TESShout**	  shouts;		 // 10
			std::uint32_t numSpells;	 // 18
			std::uint32_t numlevSpells;	 // 1C
			std::uint32_t numShouts;	 // 20
			std::uint32_t pad24;		 // 24
		};
		static_assert(sizeof(SpellData) == 0x28);

		virtual ~TESSpellList();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { return; }
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// members
		SpellData* actorEffects;  // 08 - SPLO
	};
	static_assert(sizeof(TESSpellList) == 0x10);
}
