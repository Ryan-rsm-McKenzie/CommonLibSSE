#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSPerk;

	struct PerkRankData	 // PRKR
	{
		BGSPerk*	  perk;			// 00
		std::int8_t	  currentRank;	// 08
		std::uint8_t  pad09;		// 09
		std::uint16_t pad0A;		// 0A
		std::uint32_t pad0C;		// 0C
	};
	static_assert(sizeof(PerkRankData) == 0x10);

	class BGSPerkRankArray : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSPerkRankArray;

		virtual ~BGSPerkRankArray();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;			  // 01 - { return; }
		virtual void ClearDataComponent() override;					  // 02
		virtual void CopyComponent(BaseFormComponent* rhs) override;  // 03

		// members
		PerkRankData* perks;	  // 08 - PRKR
		std::uint32_t perkCount;  // 10 - PRKZ
		std::uint32_t pad14;	  // 14
	};
	static_assert(sizeof(BGSPerkRankArray) == 0x18);
}
