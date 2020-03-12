#pragma once

#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSEquipSlot : TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSEquipSlot;
		inline static constexpr auto FORMTYPE = FormType::EquipSlot;


		enum class Flag : UInt32  // DATA
		{
			kNone = 0,
			kUseAllParents = 1 << 0,
			kParentsOptional = 1 << 1,
			kItemSlot = 1 << 2
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSEquipSlot();  // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		BSTArray<BGSEquipSlot*> parentSlots;  // 20 - PNAM
		Flag					flags;		  // 38 - DATA
		UInt32					pad3C;		  // 3C
	};
	STATIC_ASSERT(sizeof(BGSEquipSlot) == 0x40);
}
