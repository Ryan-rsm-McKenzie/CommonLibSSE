#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class BGSPerk;


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
		virtual void	InitializeDataComponent() override;				// 01 - { return; }
		virtual void	ClearDataComponent() override;					// 02
		virtual void	CopyComponent(BaseFormComponent* rhs) override;	// 03


		// members
		Entry*	perkRanks;		// 08
		UInt32	numPerkRanks;	// 10
		UInt32	pad14;			// 14
	};
	STATIC_ASSERT(sizeof(BGSPerkRankArray) == 0x18);
}
