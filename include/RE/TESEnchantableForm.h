#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class EnchantmentItem;


	class TESEnchantableForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESEnchantableForm;


		virtual ~TESEnchantableForm();										// 00

		// override (BaseFormComponent)
		virtual void	InitializeDataComponent() override;					// 01
		virtual void	ClearDataComponent() override;						// 02
		virtual void	CopyComponent(BaseFormComponent* a_rhs) override;	// 03

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
