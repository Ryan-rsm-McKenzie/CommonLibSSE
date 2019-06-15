#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESLeveledList

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/FormTypes.h"  // FormType, TESForm, TESGlobal, TESFaction


namespace RE
{
	class TESLeveledList : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESLeveledList;


		struct Entry
		{
			struct BaseData	// LVLO
			{
				TESForm*	reference;	// 00
				UInt16		count;		// 08
				UInt16		level;		// 0A
				UInt32		pad0C;		// 0C
			};
			STATIC_ASSERT(sizeof(BaseData) == 0x10);


			struct ExtraData	// COED
			{
				TESFaction*	owner;			// 00
				SInt32		requiredRank;	// 08
				UInt32		unk0C;			// 0C
				float		itemCondition;	// 10
				UInt32		unk14;			// 14
			};
			STATIC_ASSERT(sizeof(ExtraData) == 0x18);


			BaseData	baseData;	// 00
			ExtraData*	extraData;	// 10
		};
		STATIC_ASSERT(sizeof(Entry) == 0x18);


		enum Flag : UInt8	// LVLF
		{
			kCalculateFromAllLevelsLTOrEqPCLevel = 1 << 0,
			kCalculateForEachItemInCount = 1 << 1,
			kUseAll = 1 << 2,
			kSpecialLoot = 1 << 3
		};


		virtual ~TESLeveledList();											// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual UInt8	GetLevChanceValue();								// 04 - { if (global) return global->value; else return chanceNone; }
		virtual bool	CalculateForEachItemInCount();						// 05 - { return (flags >> 1) & 1; }
		virtual SInt32	GetLevDifferenceMax();								// 06 - { return 0; }
		virtual bool	IsValidLevItem(FormType a_formType) = 0;			// 07


		// members
		Entry*		entries;		// 08
		UInt8		chanceNone;		// 10 - LVLD
		Flag		flags;			// 11 - LVLF
		UInt8		numEntries;		// 12 - LLCT
		UInt8		unk13;			// 13
		UInt32		pad14;			// 14
		void*		unk18;			// 18
		TESGlobal*	global;			// 20 - LVLG
	};
	STATIC_ASSERT(sizeof(TESLeveledList) == 0x28);
}
