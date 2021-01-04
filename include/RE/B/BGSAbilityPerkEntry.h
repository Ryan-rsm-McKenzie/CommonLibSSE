#pragma once

#include "RE/B/BGSPerkEntry.h"

namespace RE
{
	class SpellItem;

	class BGSAbilityPerkEntry : public BGSPerkEntry
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSAbilityPerkEntry;

		virtual ~BGSAbilityPerkEntry();	 // 00

		// override (BGSPerkEntry)
		virtual PERK_ENTRY_TYPE GetType() const override;				   // 04 - { return kAbility; }
		virtual void			InitItem(TESFile* a_owner) override;	   // 06
		virtual bool			Load(TESFile* a_file) override;			   // 07
		virtual void			ApplyPerkEntry(Actor* a_actor) override;   // 0A
		virtual void			RemovePerkEntry(Actor* a_actor) override;  // 0B

		// members
		SpellItem* ability;	 // 10
	};
	static_assert(sizeof(BGSAbilityPerkEntry) == 0x18);
}
