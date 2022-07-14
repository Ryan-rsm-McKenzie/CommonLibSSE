#pragma once

#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/P/PerkRankVisitor.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"

namespace RE
{
	class BGSPerkEntry;

	struct PerkData  // DATA
	{
		bool        trait;     // 0
		std::int8_t level;     // 1
		std::int8_t numRanks;  // 2
		bool        playable;  // 3
		bool        hidden;    // 4
	};
	static_assert(sizeof(PerkData) == 0x5);

	class BGSPerk :
		public TESForm,         // 00
		public TESFullName,     // 20
		public TESDescription,  // 30
		public TESIcon          // 40
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSPerk;
		inline static constexpr auto VTABLE = VTABLE_BGSPerk;
		inline static constexpr auto FORMTYPE = FormType::Perk;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
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
			bool operator()(const PerkRankData* a_entry) override;  // 00
		};
		static_assert(sizeof(FindPerkInRanksVisitor) == 0x8);

		class ApplyPerksVisitor : public PerkRankVisitor
		{
		public:
			inline static constexpr auto RTTI = RTTI_BGSPerk__ApplyPerksVisitor;

			// override (PerkRankVisitor)
			bool operator()(const PerkRankData* a_entry) override;  // 00
		};
		static_assert(sizeof(ApplyPerksVisitor) == 0x8);

		class AddPerkVisitor : public PerkRankVisitor
		{
		public:
			inline static constexpr auto RTTI = RTTI_BGSPerk__AddPerkVisitor;

			// override (PerkRankVisitor)
			bool operator()(const PerkRankData* a_entry) override;  // 00
		};
		static_assert(sizeof(AddPerkVisitor) == 0x8);

		~BGSPerk() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		PerkData                data;            // 50 - DATA
		std::uint8_t            pad55;           // 55
		std::uint16_t           pad56;           // 56
		TESCondition            perkConditions;  // 58
		BSTArray<BGSPerkEntry*> perkEntries;     // 60
		BGSPerk*                nextPerk;        // 78 - NNAM
	};
	static_assert(sizeof(BGSPerk) == 0x80);
}
