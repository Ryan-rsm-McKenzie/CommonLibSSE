#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/T/TESIcon.h"

namespace RE
{
	class BGSMessageIcon : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMessageIcon;

		~BGSMessageIcon() override;  // 00

		// override (BaseFormComponent)
		void InitializeDataComponent() override;                // 01
		void ClearDataComponent() override;                     // 02 - { icon.ReleaseRefs(); }
		void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		TESIcon icon;  // 08
	};
	static_assert(sizeof(BGSMessageIcon) == 0x18);
}
