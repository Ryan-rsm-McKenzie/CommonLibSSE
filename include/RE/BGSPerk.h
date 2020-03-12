#pragma once

#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/PerkRankVisitor.h"
#include "RE/TESCondition.h"
#include "RE/TESDescription.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"
#include "RE/TESIcon.h"


namespace RE
{
	class BGSPerkEntry;


	struct PerkData	 // DATA
	{
		bool  trait;	 // 0
		SInt8 level;	 // 1
		SInt8 numRanks;	 // 2
		bool  playable;	 // 3
		bool  hidden;	 // 4
	};
	STATIC_ASSERT(sizeof(PerkData) == 0x5);


	class BGSPerk :
		public TESForm,			// 00
		public TESFullName,		// 20
		public TESDescription,	// 30
		public TESIcon			// 40
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSPerk;
		inline static constexpr auto FORMTYPE = FormType::Perk;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		class FindPerkInRanksVisitor : public PerkRankVisitor
		{
		public:
			inline static constexpr auto RTTI = RTTI_BGSPerk__FindPerkInRanksVisitor;

			// override (PerkRankVisitor)
			virtual bool operator()(const PerkRankData* a_entry) override;	// 00
		};
		STATIC_ASSERT(sizeof(FindPerkInRanksVisitor) == 0x8);


		class ApplyPerksVisitor : public PerkRankVisitor
		{
		public:
			inline static constexpr auto RTTI = RTTI_BGSPerk__ApplyPerksVisitor;

			// override (PerkRankVisitor)
			virtual bool operator()(const PerkRankData* a_entry) override;	// 00
		};
		STATIC_ASSERT(sizeof(ApplyPerksVisitor) == 0x8);


		class AddPerkVisitor : public PerkRankVisitor
		{
		public:
			inline static constexpr auto RTTI = RTTI_BGSPerk__AddPerkVisitor;

			// override (PerkRankVisitor)
			virtual bool operator()(const PerkRankData* a_entry) override;	// 00
		};
		STATIC_ASSERT(sizeof(AddPerkVisitor) == 0x8);


		virtual ~BGSPerk();	 // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		PerkData				data;			 // 50 - DATA
		UInt8					pad55;			 // 55
		UInt16					pad56;			 // 56
		TESCondition			perkConditions;	 // 58
		BSTArray<BGSPerkEntry*> perkEntries;	 // 60
		BGSPerk*				nextPerk;		 // 78 - NNAM
	};
	STATIC_ASSERT(sizeof(BGSPerk) == 0x80);
}
