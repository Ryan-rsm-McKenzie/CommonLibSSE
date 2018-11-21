#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent
#include "skse64/GameTypes.h"  // tArray

#include "RE/BSTArray.h"  // BSScrapArray

class TESForm;
class TESGlobal;


namespace RE
{
	class TESLeveledList : public BaseFormComponent
	{
	public:
		struct Entry
		{
			TESForm*	form;	// 00 - init'd to 0
			UInt16		count;	// 08 - init'd to 1
			UInt16		level;	// 0A - init'd to 1
			UInt32		pad0C;	// 0C
			UInt64		unk10;	// 10 - init'd to 0
		};


		struct CalculatedResult
		{
			TESForm*	form;		// 00
			UInt32		count;		// 08
			UInt32		pad0C;		// 0C
			void*		unk10;		// 10
			void*		unk18;		// 18
			float		unk20;		// 20
		};


		enum Flag : UInt8
		{
			kFlagCalculateFromAllLevelsLTPCLevel	= 1 << 0,
			kFlagCalculateForEachItemInCount		= 1 << 1,
			kFlagUseAll								= 1 << 2,
			kFlagSpecialLoot						= 1 << 3
		};


		virtual UInt8	GetLevChanceValue();					// 4
		virtual bool	HasFlagUseAll();						// 5
		virtual SInt32	GetLevDifferenceMax();					// 6 - nullsub
		virtual bool	IsValidLevItem(UInt32 a_formType) = 0;	// 7


		// members
		Entry*		entries;		// 08
		UInt8		chanceValue;	// 10
		Flag		flags;			// 11
		UInt8		length;			// 12
		UInt8		unk0B;			// 13
		UInt32		pad14;			// 14
		void*		unk18;			// 18
		TESGlobal*	chanceGlobal;	// 20
	};
	STATIC_ASSERT(sizeof(TESLeveledList) == 0x28);
}
