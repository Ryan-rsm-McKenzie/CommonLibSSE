#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/FormTypes.h"


namespace RE
{
	class BGSBlockBashData : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSBlockBashData;


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
