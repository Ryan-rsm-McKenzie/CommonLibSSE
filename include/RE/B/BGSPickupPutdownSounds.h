#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSSoundDescriptorForm;

	class BGSPickupPutdownSounds : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSPickupPutdownSounds;

		virtual ~BGSPickupPutdownSounds();	// 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02 - { return; }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// members
		BGSSoundDescriptorForm* pickupSound;   // 08 - YNAM
		BGSSoundDescriptorForm* putdownSound;  // 10 - ZNAM
	};
	static_assert(sizeof(BGSPickupPutdownSounds) == 0x18);
}
