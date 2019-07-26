#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESObjectBOOK

#include <type_traits>  // underlying_type_t

#include "RE/ActorValues.h"  // ActorValue
#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BGSMessageIcon.h"  // BGSMessageIcon
#include "RE/BGSPickupPutdownSounds.h"  // BGSPickupPutdownSounds
#include "RE/FormTypes.h"  // FormType, SpellItem, TESObjectSTAT
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESDescription.h"  // TESDescription
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESIcon.h"  // TESIcon
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap
#include "RE/TESValueForm.h"  // TESValueForm
#include "RE/TESWeightForm.h"  // TESWeightForm


namespace RE
{
	class TESObjectBOOK :
		public TESBoundObject,				// 00
		public TESFullName,					// 30
		public TESModelTextureSwap,			// 40
		public TESIcon,						// 78
		public TESValueForm,				// 88
		public TESWeightForm,				// 98
		public TESDescription,				// A8
		public BGSDestructibleObjectForm,	// B8
		public BGSMessageIcon,				// C8
		public BGSPickupPutdownSounds,		// E0
		public BGSKeywordForm				// F8
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectBOOK;


		enum { kTypeID = FormType::Book };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DATA
		{
			enum class Flag : UInt8
			{
				kNone = 0,
				kTeachesSkill = 1 << 0,
				kCantBeTaken = 1 << 1,
				kTeachesSpell = 1 << 2,	// takes priority over skill
				kRead = 1 << 3,			// set once the book is equipped by the player, along with the CHANGE_BOOK_READ (0x40) change flag
			};


			enum class Type : UInt8
			{
				kBookTome = 0x00,
				kNoteScroll = static_cast<std::underlying_type_t<Type>>(-1),
			};


			union Teaches
			{
				ActorValue	skill;
				SpellItem*	spell;
			};
			STATIC_ASSERT(sizeof(Teaches) == 0x8);


			Flag GetSanitizedType() const;


			// members
			Flag	flags;		// 00
			Type	type;		// 01
			UInt16	pad02;		// 02
			UInt32	pad04;		// 04
			Teaches	teaches;	// 08
		};
		STATIC_ASSERT(sizeof(Data) == 0x10);

		virtual ~TESObjectBOOK();																																	// 00

		// override (TESBoundObject)
		virtual void	InitDefaults() override;																													// 04
		virtual void	ReleaseManagedData() override;																												// 05 - { return TESForm::ReleaseManagedData(); }
		virtual bool	LoadForm(TESFile* a_mod) override;																											// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;																								// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;																								// 0F
		virtual void	InitItem() override;																														// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual bool	GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst) override;																			// 4D

		bool		TeachesSkill() const;
		bool		TeachesSpell() const;
		bool		IsRead() const;
		bool		CanBeTaken() const;
		bool		IsBookTome() const;
		bool		IsNoteScroll() const;
		ActorValue	GetSkill() const;
		SpellItem*	GetSpell();


		// members
		Data			data;			// 110 - DATA
		TESObjectSTAT*	inventoryArt;	// 120 - INAM
		TESDescription	description;	// 128 - CNAM
	};
	STATIC_ASSERT(sizeof(TESObjectBOOK) == 0x138);
}
