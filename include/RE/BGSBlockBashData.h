#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent


namespace RE
{
	class BGSImpactDataSet;
	class BGSMaterialType;


	class BGSBlockBashData : public BaseFormComponent
	{
	public:
		virtual ~BGSBlockBashData();										// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01 - { impact = 0; material = 0; }
		virtual void	ReleaseRefs() override;								// 02 - { return; }
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		BGSImpactDataSet*	bashImpactDataSet;		// 08 - BIDS
		BGSMaterialType*	alternateBlockMaterial;	// 10 - BAMT
	};
	STATIC_ASSERT(sizeof(BGSBlockBashData) == 0x18);
}
