#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class BGSPerk;


	struct PerkRankData	 // PRKR
	{
		BGSPerk* perk;		   // 00
		SInt8	 currentRank;  // 08
		UInt8	 pad09;		   // 09
		UInt16	 pad0A;		   // 0A
		UInt32	 pad0C;		   // 0C
	};
	STATIC_ASSERT(sizeof(PerkRankData) == 0x10);


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
		UInt32		  perkCount;  // 10 - PRKZ
		UInt32		  pad14;	  // 14
	};
	STATIC_ASSERT(sizeof(BGSPerkRankArray) == 0x18);
}
