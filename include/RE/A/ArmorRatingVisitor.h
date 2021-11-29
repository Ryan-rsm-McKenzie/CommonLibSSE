#pragma once

#include "RE/A/ArmorRatingVisitorBase.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class ArmorRatingVisitor : public ArmorRatingVisitorBase
	{
	public:
		inline static constexpr auto RTTI = RTTI___ArmorRatingVisitor;

		~ArmorRatingVisitor() override;  // 00

		// override (ArmorRatingVisitorBase)
		bool HaveNotVisitedArmor(TESObjectARMO* a_armor) override;  // 04
		void VisitArmor(TESObjectARMO* a_armor) override;           // 05

		// members
		BSScrapArray<TESObjectARMO*> armors;  // 20
	};
	static_assert(sizeof(ArmorRatingVisitor) == 0x40);
}
