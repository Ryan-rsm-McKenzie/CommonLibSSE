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
		inline static constexpr auto RTTI = RTTI_TESLevItem;
		inline static constexpr auto FORMTYPE = FormType::LeveledItem;


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


		virtual ~TESLevItem();	// 00

		// override (TESBoundObject)
		virtual bool Load(TESFile* a_mod) override;				   // 06
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;	   // 12
		virtual void InitItemImpl() override;					   // 13

		// override (TESLeveledList)
		virtual SInt32 GetLevDifferenceMax() override;							  // 06 - { return iLevItemLevelDifferenceMax; }
		virtual bool   GetCanContainFormsOfType(FormType a_type) const override;  // 07
	};
	STATIC_ASSERT(sizeof(TESLevItem) == 0x58);
}
