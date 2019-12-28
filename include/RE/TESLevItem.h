#pragma once

#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"
#include "RE/TESLeveledList.h"


namespace RE
{
	class TESLevItem :
		public TESBoundObject,	// 00
		public TESLeveledList	// 30
	{
	public:
		inline static const void* RTTI = RTTI_TESLevItem;


		enum { kTypeID = FormType::LeveledItem };


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kAddedObject = (UInt32)1 << 31
			};
		};


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
		virtual bool	Load(TESFile* a_mod) override;					// 06
		virtual void	SaveGame(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadGame(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Revert(void* a_arg1) override;					// 12
		virtual void	InitItemImpl() override;						// 13

		// override (TESLeveledList)
		virtual SInt32	GetLevDifferenceMax() override;					// 06 - { return iLevItemLevelDifferenceMax; }
		virtual bool	IsValidLevItem(FormType a_formType) override;	// 07
	};
	STATIC_ASSERT(sizeof(TESLevItem) == 0x58);
}
