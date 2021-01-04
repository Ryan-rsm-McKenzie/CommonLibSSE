#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESLeveledList.h"

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
			enum ChangeFlag : std::uint32_t
			{
				kAddedObject = (std::uint32_t)1 << 31
			};
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
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
		virtual std::int32_t GetLevDifferenceMax() override;							// 06 - { return iLevItemLevelDifferenceMax; }
		virtual bool		 GetCanContainFormsOfType(FormType a_type) const override;	// 07
	};
	static_assert(sizeof(TESLevItem) == 0x58);
}
