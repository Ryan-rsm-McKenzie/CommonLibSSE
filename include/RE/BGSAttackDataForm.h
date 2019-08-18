#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSAttackDataForm

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class BGSAttackDataMap;


	class BGSAttackDataForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSAttackDataForm;


		virtual ~BGSAttackDataForm();										// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01 - { return; }
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		NiPointer<BGSAttackDataMap> attackDataMap;	// 08
	};
	STATIC_ASSERT(sizeof(BGSAttackDataForm) == 0x10);
}
