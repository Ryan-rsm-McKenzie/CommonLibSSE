#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/F/FormTypes.h"

namespace RE
{
	class BGSBlockBashData : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSBlockBashData;

		virtual ~BGSBlockBashData();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { impact = 0; material = 0; }
		virtual void ClearDataComponent() override;						// 02 - { return; }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// members
		BGSImpactDataSet* blockBashImpactDataSet;  // 08 - BIDS
		BGSMaterialType*  altBlockMaterialType;	   // 10 - BAMT
	};
	static_assert(sizeof(BGSBlockBashData) == 0x18);
}
