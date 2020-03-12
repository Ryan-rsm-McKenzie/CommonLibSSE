#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/ContainerItemExtra.h"
#include "RE/MemoryManager.h"


namespace RE
{
	class TESFaction;
	class TESForm;
	class TESGlobal;


	struct LEVELED_OBJECT
	{
		TESForm*			form;		// 00 - LVLO~
		UInt16				count;		// 08
		UInt16				level;		// 0A - ~LVLO
		UInt32				pad0C;		// 0C
		ContainerItemExtra* itemExtra;	// 10 - COED
	};
	STATIC_ASSERT(sizeof(LEVELED_OBJECT) == 0x18);


	class TESLeveledList : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESLeveledList;


		enum Flag : UInt8  // LVLF
		{
			kCalculateFromAllLevelsLTOrEqPCLevel = 1 << 0,
			kCalculateForEachItemInCount = 1 << 1,
			kUseAll = 1 << 2,
			kSpecialLoot = 1 << 3
		};


		virtual ~TESLeveledList();	// 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual UInt8  GetChanceNone();										 // 04 - { if (global) return global->value; else return chanceNone; }
		virtual bool   GetMultCalc();										 // 05 - { return (flags >> 1) & 1; }
		virtual SInt32 GetLevDifferenceMax();								 // 06 - { return 0; }
		virtual bool   GetCanContainFormsOfType(FormType a_type) const = 0;	 // 07


		// members
		SimpleArray<LEVELED_OBJECT> entries;	   // 08
		SInt8						chanceNone;	   // 10 - LVLD
		Flag						llFlags;	   // 11 - LVLF
		UInt8						numEntries;	   // 12 - LLCT
		UInt8						unk13;		   // 13
		UInt32						pad14;		   // 14
		void*						unk18;		   // 18
		TESGlobal*					chanceGlobal;  // 20 - LVLG
	};
	STATIC_ASSERT(sizeof(TESLeveledList) == 0x28);
}
