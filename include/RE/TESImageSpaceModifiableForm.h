#pragma once

#include "RE/BaseFormComponent.h"  // BaseFormComponent


namespace RE
{
	class TESImageSpaceModifier;


	class TESImageSpaceModifiableForm : public BaseFormComponent
	{
	public:
		virtual ~TESImageSpaceModifiableForm();								// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01 - { unk08 = 0; }
		virtual void	ReleaseRefs() override;								// 02 - { return; }
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		TESImageSpaceModifier* imageSpaceModifier;	// 08 - MNAM
	};
	STATIC_ASSERT(sizeof(TESImageSpaceModifiableForm) == 0x10);
}
