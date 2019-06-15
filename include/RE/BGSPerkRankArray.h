#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSPerkRankArray

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/FormTypes.h"  // BGSPerk


namespace RE
{
	class BGSPerkRankArray : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSPerkRankArray;


		struct Entry
		{
			BGSPerk*	perk;	// 00
			UInt8		rank;	// 08
			UInt8		pad09;	// 09
			UInt16		pad0A;	// 0A
			UInt32		pad0C;	// 0C
		};
		STATIC_ASSERT(sizeof(Entry) == 0x10);


		virtual ~BGSPerkRankArray();									// 00

		// override (BaseFormComponent)
		virtual void	Init() override;								// 01 - { return; }
		virtual void	ReleaseRefs() override;							// 02
		virtual void	CopyFromBase(BaseFormComponent* rhs) override;	// 03


		// members
		Entry*	perkRanks;		// 08
		UInt32	numPerkRanks;	// 10
		UInt32	pad14;			// 14
	};
	STATIC_ASSERT(sizeof(BGSPerkRankArray) == 0x18);
}
