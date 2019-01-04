#pragma once

#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSEquipSlot : TESForm
	{
	public:
		enum { kTypeID = FormType::EquipSlot };


		enum class Flag : UInt32	// DATA
		{
			kNone = 0,
			kUseAllParents = 1 << 0
		};


		virtual ~BGSEquipSlot();							// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		BSTArray<BGSEquipSlot*>	parentSlots;	// 20 - PNAM
		Flag					flags;			// 38 - DATA
		UInt32					pad3C;			// 3C
	};
	STATIC_ASSERT(sizeof(BGSEquipSlot) == 0x40);
}
