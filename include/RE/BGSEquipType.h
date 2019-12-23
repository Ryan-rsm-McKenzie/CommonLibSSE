#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/FormTypes.h"


namespace RE
{
	class BGSEquipType : public BaseFormComponent	// EQUP
	{
	public:
		inline static const void* RTTI = RTTI_BGSEquipType;


		virtual ~BGSEquipType();													// 00

		// override (BaseFormComponent)
		virtual void			InitializeDataComponent() override;					// 01 - { equipmentType = 0; }
		virtual void			ClearDataComponent() override;						// 02 - { return; }
		virtual void			CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual	BGSEquipSlot*	GetEquipSlot();										// 04 - { return equipmentType; }
		virtual void			SetEquipSlot(BGSEquipSlot* a_slot);					// 05 - { equipmentType = a_slot; }


		// members
		BGSEquipSlot* equipmentType;	// 08 - ETYP
	};
	STATIC_ASSERT(sizeof(BGSEquipType) == 0x10);
}
