#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSAbilityPerkEntry

#include "RE/BGSPerkEntry.h"  // BGSPerkEntry


namespace RE
{
	class SpellItem;


	class BGSAbilityPerkEntry : public BGSPerkEntry
	{
	public:
		inline static const void* RTTI = RTTI_BGSAbilityPerkEntry;


		virtual ~BGSAbilityPerkEntry();						// 00

		// override (BGSPerkEntry)
		virtual Type	GetType() const override;			// 04 - { return kAbility; }
		virtual void	ResolveForms(TESFile* a_mod);		// 06
		virtual bool	LoadPerk(TESFile* a_mod) override;	// 07
		virtual void	Unk_0A(void) override;				// 0A
		virtual void	Unk_0B(void) override;				// 0B


		// members
		SpellItem* ability;	// 10
	};
	STATIC_ASSERT(sizeof(BGSAbilityPerkEntry) == 0x18);
}
