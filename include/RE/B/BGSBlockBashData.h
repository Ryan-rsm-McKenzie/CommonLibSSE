#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/F/FormTypes.h"

namespace RE
{
	class BGSBlockBashData : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSBlockBashData;

		~BGSBlockBashData() override;  // 00

		// override (BaseFormComponent)
		void InitializeDataComponent() override;                // 01 - { impact = 0; material = 0; }
		void ClearDataComponent() override;                     // 02 - { return; }
		void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		BGSImpactDataSet* blockBashImpactDataSet;  // 08 - BIDS
		BGSMaterialType*  altBlockMaterialType;    // 10 - BAMT
	};
	static_assert(sizeof(BGSBlockBashData) == 0x18);
}
