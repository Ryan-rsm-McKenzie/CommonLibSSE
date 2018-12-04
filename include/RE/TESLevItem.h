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
		enum { kTypeID = FormType::LeveledItem };


		virtual ~TESLevItem();											// 00

		// override (TESBoundObject)
		virtual bool	LoadForm(TESFile* a_mod) override;				// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	InitItem() override;							// 13

		// override (TESLeveledList)
		virtual SInt32	GetLevDifferenceMax() override;					// 06
		virtual bool	IsValidLevItem(UInt32 a_formType) override;		// 07

		bool			IsValidInventoryItem() const;
	};
	STATIC_ASSERT(sizeof(TESLevItem) == 0x58);
}
