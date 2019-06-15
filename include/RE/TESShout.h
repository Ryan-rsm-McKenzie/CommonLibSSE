#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESShout

#include "RE/BGSEquipType.h"  // BGSEquipType
#include "RE/BGSMenuDisplayObject.h"  // BGSMenuDisplayObject
#include "RE/FormTypes.h"  // FormType
#include "RE/TESDescription.h"  // TESDescription
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName


namespace RE
{
	class TESShout :
		public TESForm,					// 00
		public TESFullName,				// 20
		public BGSMenuDisplayObject,	// 30
		public BGSEquipType,			// 40
		public TESDescription			// 50
	{
	public:
		inline static const void* RTTI = RTTI_TESShout;


		enum { kTypeID = FormType::Shout };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kTreatSpellsAsPowers = 1 << 7,
				kIgnored = 1 << 12
			};
		};


		struct WordOfPower	// SNAM
		{
			TESWordOfPower*	word;			// 00
			SpellItem*		spell;			// 08
			float			recoveryTime;	// 10
			UInt32			pad14;			// 14
		};
		STATIC_ASSERT(sizeof(WordOfPower) == 0x18);


		struct Levels
		{
			enum
			{
				kLevel1,
				kLevel2,
				kLevel3,

				kTotal
			};
		};


		virtual ~TESShout();								// 00

		// override (TESForm)
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13
		virtual bool	PlayerKnows() const override;		// 17


		// members
		WordOfPower wordsOfPower[Levels::kTotal];	// 60 - SNAM
	};
	STATIC_ASSERT(sizeof(TESShout) == 0xA8);
}
