#pragma once

#include "RE/I/InventoryChanges.h"

namespace RE
{
	class ArmorRatingVisitorBase : public InventoryChanges::IItemChangeVisitor
	{
	public:
		inline static constexpr auto RTTI = RTTI___ArmorRatingVisitorBase;

		virtual ~ArmorRatingVisitorBase();	// 00

		// override (InventoryChanges::IItemChangeVisitor)
		bool Visit(InventoryEntryData* a_entryData) override;  // 01

		// add
		virtual bool HaveNotVisitedArmor(TESObjectARMO* a_armor);  // 04 - { return true; }
		virtual void VisitArmor(TESObjectARMO* a_armor);		   // 05 - { return; }

		// members
		Actor* actor;			  // 08
		float  armorSum;		  // 10
		float  armorPerks;		  // 14
		float  lightArmorRating;  // 18
		float  heavyArmorRating;  // 1C
	};
	static_assert(sizeof(ArmorRatingVisitorBase) == 0x20);
}
