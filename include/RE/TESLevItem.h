#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESLevItem

#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESLeveledList.h"  // TESLeveledList


namespace RE
{
	class TESLevItem :
		public TESBoundObject,	// 00
		public TESLeveledList	// 30
	{
	public:
		inline static const void* RTTI = RTTI_TESLevItem;


		enum { kTypeID = FormType::LeveledItem };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESLevItem();											// 00

		// override (TESBoundObject)
		virtual bool	LoadForm(TESFile* a_mod) override;				// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Unk_12(void) override;							// 12
		virtual void	InitItem() override;							// 13

		// override (TESLeveledList)
		virtual SInt32	GetLevDifferenceMax() override;					// 06 - { return iLevItemLevelDifferenceMax; }
		virtual bool	IsValidLevItem(FormType a_formType) override;	// 07
	};
	STATIC_ASSERT(sizeof(TESLevItem) == 0x58);
}
