#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESWeightForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESWeightForm;

		virtual ~TESWeightForm();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { weight = 0.0; }
		virtual void ClearDataComponent() override;						// 02 - { return; }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// members
		float		  weight;  // 08
		std::uint32_t pad0C;   // 0C
	};
	static_assert(sizeof(TESWeightForm) == 0x10);
}
