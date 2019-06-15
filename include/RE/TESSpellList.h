#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESSpellList

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/FormTypes.h"  // SpellItem, TESLevSpell, TESShout


namespace RE
{
	class TESSpellList : BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESSpellList;


		struct ActorEffect	// SPLO
		{
			SpellItem**		spells;				// 00
			TESLevSpell**	leveledSpells;		// 08
			TESShout**		shouts;				// 10
			UInt32			numSpells;			// 18
			UInt32			numleveledSpells;	// 1C
			UInt32			numShouts;			// 20
			UInt32			pad24;				// 24
		};
		STATIC_ASSERT(sizeof(ActorEffect) == 0x28);


		virtual ~TESSpellList();											// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01 - { return; }
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		ActorEffect* actorEffects;	// 08 - SPLO
	};
	STATIC_ASSERT(sizeof(TESSpellList) == 0x10);
}
