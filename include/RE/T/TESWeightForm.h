#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESWeightForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESWeightForm;

		~TESWeightForm() override;  // 00

		// override (BaseFormComponent)
		void InitializeDataComponent() override;                // 01 - { weight = 0.0; }
		void ClearDataComponent() override;                     // 02 - { return; }
		void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		float         weight;  // 08
		std::uint32_t pad0C;   // 0C
	};
	static_assert(sizeof(TESWeightForm) == 0x10);
}
