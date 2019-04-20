#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESEnchantableForm

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/FormTypes.h"  // EnchantmentItem


namespace RE
{
	class TESEnchantableForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESEnchantableForm;


		virtual ~TESEnchantableForm();										// 00

		// override (BaseFormComponent0
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual UInt16	GetUnk10();											// 04


		// members
		EnchantmentItem*	objectEffect;		// 08 - EITM
		UInt16				unk10;				// 10
		UInt16				enchantmentAmount;	// 12 - EAMT
		UInt32				pad14;				// 14
	};
	STATIC_ASSERT(sizeof(TESEnchantableForm) == 0x18);
}
