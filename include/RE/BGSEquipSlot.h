#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSEquipSlot

#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSEquipSlot : TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSEquipSlot;


		enum { kTypeID = FormType::EquipSlot };


		enum class Flag : UInt32	// DATA
		{
			kNone = 0,
			kUseAllParents = 1 << 0
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSEquipSlot();							// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		BSTArray<BGSEquipSlot*>	slotParents;	// 20 - PNAM
		Flag					flags;			// 38 - DATA
		UInt32					pad3C;			// 3C
	};
	STATIC_ASSERT(sizeof(BGSEquipSlot) == 0x40);
}
