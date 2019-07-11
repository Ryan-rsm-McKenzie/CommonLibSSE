#pragma once

#include "RE/InventoryChanges.h"  // InventoryChanges::IItemChangeVisitor


namespace RE
{
	class ArmorRatingVisitorBase : public InventoryChanges::IItemChangeVisitor
	{
	public:
		virtual ~ArmorRatingVisitorBase();									// 00

		// override (InventoryChanges::IItemChangeVisitor)
		virtual bool	Visit(InventoryEntryData* a_entryData) override;	// 01

		// add
		virtual bool	HaveNotVisitedArmor(TESObjectARMO* a_armor);			// 04 - { return true; }
		virtual void	VisitArmor(TESObjectARMO* a_armor);						// 05 - { return; }


		// members
		Actor*	actor;				// 08
		float	unk10;				// 10
		float	armorPerks;			// 14
		float	lightArmorRating;	// 18
		float	heavyArmorRating;	// 1C
	};
	STATIC_ASSERT(sizeof(ArmorRatingVisitorBase) == 0x20);
}
