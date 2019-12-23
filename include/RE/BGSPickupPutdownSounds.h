#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class BGSSoundDescriptorForm;


	class BGSPickupPutdownSounds : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSPickupPutdownSounds;


		virtual ~BGSPickupPutdownSounds();									// 00

		// override (BaseFormComponent)
		virtual void	InitializeDataComponent() override;					// 01
		virtual void	ClearDataComponent() override;						// 02 - { return; }
		virtual void	CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		BGSSoundDescriptorForm*	pickUp;		// 08 - YNAM
		BGSSoundDescriptorForm*	putDown;	// 10 - ZNAM
	};
	STATIC_ASSERT(sizeof(BGSPickupPutdownSounds) == 0x18);
}
