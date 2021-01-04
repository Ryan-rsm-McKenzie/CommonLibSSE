#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESObjectARMO;

	class BGSSkinForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSSkinForm;

		virtual ~BGSSkinForm();	 // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02 - { return; }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// members
		TESObjectARMO* skin;  // 08 - WNAM
	};
	static_assert(sizeof(BGSSkinForm) == 0x10);
}
