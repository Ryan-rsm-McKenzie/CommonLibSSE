#pragma once

#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSRelationship : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSRelationship;
		inline static constexpr auto FORMTYPE = FormType::Relationship;


		enum class RELATIONSHIP_LEVEL : UInt8
		{
			kLover = 0,
			kAlly = 1,
			kConfidant = 2,
			kFriend = 3,
			kAcquaintance = 4,
			kRival = 5,
			kFoe = 6,
			kEnemy = 7,
			kArchnemesis = 8
		};


		enum class Flag : UInt8
		{
			kNone = 0,
			kSecret = 1 << 7
		};


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kRelationshipData = 1 << 1
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kSecret = 1 << 6,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSRelationship();	 // 00

		// override (TESForm)
		virtual void InitializeData() override;						   // 04
		virtual bool Load(TESFile* a_mod) override;					   // 06
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;	   // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;	   // 0F
		virtual void InitLoadGame(BGSLoadFormBuffer* a_buf) override;  // 10
		virtual void InitItemImpl() override;						   // 13


		// members
		TESNPC*				npc1;		// 20 - DATA~
		TESNPC*				npc2;		// 28
		BGSAssociationType* assocType;	// 30
		RELATIONSHIP_LEVEL	level;		// 38
		UInt8				unk39;		// 39
		UInt8				unk3A;		// 3A
		Flag				flags;		// 3B
		UInt32				pad3C;		// 3C - ~DATA
	};
	STATIC_ASSERT(sizeof(BGSRelationship) == 0x40);
}
