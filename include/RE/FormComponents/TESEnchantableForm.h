#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/MagicSystem.h"


namespace RE
{
	class EnchantmentItem;


	class TESEnchantableForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESEnchantableForm;


		virtual ~TESEnchantableForm();	// 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual MagicSystem::CastingType GetCastingType() const;  // 04 - { return castingType; }


		// members
		EnchantmentItem*		   formEnchanting;		 // 08 - EITM
		MagicSystem::CastingType16 castingType;			 // 10
		UInt16					   amountofEnchantment;	 // 12 - EAMT
		UInt32					   pad14;				 // 14
	};
	STATIC_ASSERT(sizeof(TESEnchantableForm) == 0x18);
}
