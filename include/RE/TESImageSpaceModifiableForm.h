#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class TESImageSpaceModifier;


	class TESImageSpaceModifiableForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESImageSpaceModifiableForm;


		virtual ~TESImageSpaceModifiableForm();								// 00

		// override (BaseFormComponent)
		virtual void	InitializeDataComponent() override;					// 01 - { imageSpaceModifier = 0; }
		virtual void	ClearDataComponent() override;						// 02 - { return; }
		virtual void	CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		TESImageSpaceModifier* imageSpaceModifier;	// 08 - MNAM
	};
	STATIC_ASSERT(sizeof(TESImageSpaceModifiableForm) == 0x10);
}
