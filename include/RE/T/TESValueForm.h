#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESValueForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESValueForm;

		~TESValueForm() override;  // 00

		// override (BaseFormComponent)
		void InitializeDataComponent() override;                // 01
		void ClearDataComponent() override;                     // 02 - { return; }
		void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		std::int32_t  value;  // 08
		std::uint32_t pad0C;  // 0C
	};
	static_assert(sizeof(TESValueForm) == 0x10);
}
