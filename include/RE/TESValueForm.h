#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class TESValueForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESValueForm;


		virtual ~TESValueForm();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02 - { return; }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		SInt32 value;  // 08
		UInt32 pad0C;  // 0C
	};
	STATIC_ASSERT(sizeof(TESValueForm) == 0x10);
}
