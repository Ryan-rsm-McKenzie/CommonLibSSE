#pragma once

#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSMenuDisplayObject.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class TESShout :
		public TESForm,               // 00
		public TESFullName,           // 20
		public BGSMenuDisplayObject,  // 30
		public BGSEquipType,          // 40
		public TESDescription         // 50
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESShout;
		inline static constexpr auto VTABLE = VTABLE_TESShout;
		inline static constexpr auto FORMTYPE = FormType::Shout;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kTreatSpellsAsPowers = 1 << 7,
				kIgnored = 1 << 12
			};
		};

		struct Variation  // SNAM
		{
			TESWordOfPower* word;          // 00
			SpellItem*      spell;         // 08
			float           recoveryTime;  // 10
			std::uint32_t   pad14;         // 14
		};
		static_assert(sizeof(Variation) == 0x18);

		struct VariationIDs
		{
			enum VariationID : std::uint32_t
			{
				kNone = static_cast<std::underlying_type_t<VariationID>>(-1),
				kOne = 0,
				kTwo,
				kThree,

				kTotal
			};
		};
		using VariationID = VariationIDs::VariationID;

		~TESShout() override;  // 00

		// override (TESForm)
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13
		bool GetKnown() const override;      // 17

		// override (BGSEquipType)
		BGSEquipSlot* GetEquipSlot() const override;                // 04
		void          SetEquipSlot(BGSEquipSlot* a_slot) override;  // 05 - { return; }

		// members
		Variation variations[VariationIDs::kTotal];  // 60 - SNAM
	};
	static_assert(sizeof(TESShout) == 0xA8);
}
