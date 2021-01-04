#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSRelationship : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSRelationship;
		inline static constexpr auto FORMTYPE = FormType::Relationship;

		enum class RELATIONSHIP_LEVEL
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

		enum class Flag
		{
			kNone = 0,
			kSecret = 1 << 7
		};

		struct ChangeFlags
		{
			enum ChangeFlag : std::uint32_t
			{
				kRelationshipData = 1 << 1
			};
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
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
		TESNPC*											   npc1;	   // 20 - DATA~
		TESNPC*											   npc2;	   // 28
		BGSAssociationType*								   assocType;  // 30
		stl::enumeration<RELATIONSHIP_LEVEL, std::uint8_t> level;	   // 38
		std::uint8_t									   unk39;	   // 39
		std::uint8_t									   unk3A;	   // 3A
		stl::enumeration<Flag, std::uint8_t>			   flags;	   // 3B
		std::uint32_t									   pad3C;	   // 3C - ~DATA
	};
	static_assert(sizeof(BGSRelationship) == 0x40);
}
