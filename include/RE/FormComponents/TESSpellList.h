#pragma once

#include "RE/BaseFormComponent.h"


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
			UInt32		  numSpells;	 // 18
			UInt32		  numlevSpells;	 // 1C
			UInt32		  numShouts;	 // 20
			UInt32		  pad24;		 // 24
		};
		STATIC_ASSERT(sizeof(SpellData) == 0x28);


		virtual ~TESSpellList();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { return; }
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		SpellData* actorEffects;  // 08 - SPLO
	};
	STATIC_ASSERT(sizeof(TESSpellList) == 0x10);
}
