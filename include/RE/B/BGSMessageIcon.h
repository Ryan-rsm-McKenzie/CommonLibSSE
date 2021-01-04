#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/T/TESIcon.h"

namespace RE
{
	class BGSMessageIcon : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMessageIcon;

		virtual ~BGSMessageIcon();	// 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02 - { icon.ReleaseRefs(); }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// members
		TESIcon icon;  // 08
	};
	static_assert(sizeof(BGSMessageIcon) == 0x18);
}
