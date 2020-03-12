#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class TESAttackDamageForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESAttackDamageForm;


		virtual ~TESAttackDamageForm();	 // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { attackDamage = 0; }
		virtual void ClearDataComponent() override;						// 02 - { return; }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual UInt16 GetAttackDamage() const;	 // 04 - { return attackDamage; }


		// members
		UInt16 attackDamage;  // 08
		UInt16 pad0A;		  // 0A
		UInt32 pad0C;		  // 0C
	};
	STATIC_ASSERT(sizeof(TESAttackDamageForm) == 0x10);
}
