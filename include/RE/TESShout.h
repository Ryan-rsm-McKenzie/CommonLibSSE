#pragma once

#include <type_traits>

#include "RE/BGSEquipType.h"
#include "RE/BGSMenuDisplayObject.h"
#include "RE/FormTypes.h"
#include "RE/TESDescription.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"


namespace RE
{
	class TESShout :
		public TESForm,				  // 00
		public TESFullName,			  // 20
		public BGSMenuDisplayObject,  // 30
		public BGSEquipType,		  // 40
		public TESDescription		  // 50
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESShout;
		inline static constexpr auto FORMTYPE = FormType::Shout;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kTreatSpellsAsPowers = 1 << 7,
				kIgnored = 1 << 12
			};
		};


		struct Variation  // SNAM
		{
			TESWordOfPower* word;		   // 00
			SpellItem*		spell;		   // 08
			float			recoveryTime;  // 10
			UInt32			pad14;		   // 14
		};
		STATIC_ASSERT(sizeof(Variation) == 0x18);


		struct VariationIDs
		{
			enum VariationID : UInt32
			{
				kNone = static_cast<std::underlying_type_t<VariationID>>(-1),
				kOne = 0,
				kTwo,
				kThree,

				kTotal
			};
		};
		using VariationID = VariationIDs::VariationID;


		virtual ~TESShout();  // 00

		// override (TESForm)
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13
		virtual bool GetKnown() const override;		 // 17

		// override (BGSEquipType)
		virtual BGSEquipSlot* GetEquipSlot() const override;				// 04
		virtual void		  SetEquipSlot(BGSEquipSlot* a_slot) override;	// 05 - { return; }


		// members
		Variation variations[VariationIDs::kTotal];	 // 60 - SNAM
	};
	STATIC_ASSERT(sizeof(TESShout) == 0xA8);
}
