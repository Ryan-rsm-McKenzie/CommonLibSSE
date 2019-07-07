#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSEquipType

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/FormTypes.h"  // BGSEquipSlot


namespace RE
{
	class BGSEquipType : public BaseFormComponent	// EQUP
	{
	public:
		inline static const void* RTTI = RTTI_BGSEquipType;


		virtual ~BGSEquipType();													// 00

		// override (BaseFormComponent)
		virtual void			Init() override;									// 01
		virtual void			ReleaseRefs() override;								// 02
		virtual void			CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual	BGSEquipSlot*	GetEquipSlot();										// 04
		virtual void			SetEquipSlot(BGSEquipSlot* a_slot);					// 05


		// members
		BGSEquipSlot* equipmentType;	// 08 - ETYP
	};
	STATIC_ASSERT(sizeof(BGSEquipType) == 0x10);
}
