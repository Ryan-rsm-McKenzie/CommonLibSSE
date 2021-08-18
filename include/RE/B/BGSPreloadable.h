#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSPreloadable : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSPreloadable;

		~BGSPreloadable() override;  // 00

		// override (BaseFormComponent)
		void InitializeDataComponent() override;                // 01 - { return; }
		void ClearDataComponent() override;                     // 02 - { return; }
		void CopyComponent(BaseFormComponent* a_rhs) override;  // 03 - { return; }

		// add
		virtual void Unk_04(void) = 0;  // 04
	};
	static_assert(sizeof(BGSPreloadable) == 0x8);
}
