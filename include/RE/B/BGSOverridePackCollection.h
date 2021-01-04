#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSListForm;

	class BGSOverridePackCollection : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSOverridePackCollection;

		virtual ~BGSOverridePackCollection();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02 - { return; }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// members
		BGSListForm* spectatorOverRidePackList;		 // 08 - SPOR
		BGSListForm* observeCorpseOverRidePackList;	 // 10 - OCOR
		BGSListForm* guardWarnOverRidePackList;		 // 18 - GWOR
		BGSListForm* enterCombatOverRidePackList;	 // 20 - ECOR
	};
	static_assert(sizeof(BGSOverridePackCollection) == 0x28);
}
