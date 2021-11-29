#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BGSAttackDataMap;

	class BGSAttackDataForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSAttackDataForm;

		~BGSAttackDataForm() override;  // 00

		// override (BaseFormComponent)
		void InitializeDataComponent() override;                // 01 - { return; }
		void ClearDataComponent() override;                     // 02
		void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		NiPointer<BGSAttackDataMap> attackDataMap;  // 08
	};
	static_assert(sizeof(BGSAttackDataForm) == 0x10);
}
