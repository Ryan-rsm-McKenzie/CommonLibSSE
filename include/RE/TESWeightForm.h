#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESWeightForm

#include "RE/BaseFormComponent.h"  // BaseFormComponent


namespace RE
{
	class TESWeightForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESWeightForm;


		virtual ~TESWeightForm();	// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02 - { return; }
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		float	weight;	// 08
		UInt32	pad0C;	// 0C
	};
	STATIC_ASSERT(sizeof(TESWeightForm) == 0x10);
}
