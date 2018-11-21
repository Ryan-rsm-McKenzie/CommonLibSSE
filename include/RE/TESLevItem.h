#pragma once

#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESLeveledList.h"  // TESLeveledList


namespace RE
{
	class TESLevItem :
		public TESBoundObject,	// 00
		public TESLeveledList	// 30
	{
	public:
		enum { kTypeID = kFormType_LeveledItem };


		virtual ~TESLevItem();										// 0

		// override (TESLeveledList)
		virtual SInt32	GetLevDifferenceMax() override;				// 6
		virtual bool	IsValidLevItem(UInt32 a_formType) override;	// 7

		bool			IsValidInventoryItem() const;
	};
	STATIC_ASSERT(sizeof(TESLevItem) == 0x58);
}
