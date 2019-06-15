#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESAttackDamageForm

#include "RE/BaseFormComponent.h"  // BaseFormComponent


namespace RE
{
	class TESAttackDamageForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESAttackDamageForm;


		virtual ~TESAttackDamageForm();										// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02 - { return; }
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual UInt16	GetAttackDamage() const;							// 04 - { return attackDamage; }


		// members
		UInt16	attackDamage;	// 08
		UInt16	pad0A;			// 0A
		UInt32	pad0C;			// 0C
	};
	STATIC_ASSERT(sizeof(TESAttackDamageForm) == 0x10);
}
