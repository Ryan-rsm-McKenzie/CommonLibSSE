#pragma once

#include "skse64/GameFormComponents.h"  // TESModelTextureSwap, TESIcon, TESValueForm, TESWeightForm, TESDescription, BGSDestructibleObjectForm, BGSMessageIcon, BGSPickupPutdownSounds

#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap

class SpellItem;
class TESObjectSTAT;


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
		enum { kTypeID = FormType::Book };


		struct Data
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
				kNoteScroll = 0xFF,
			};


			enum class Skill : UInt32
			{
				kNone = 0xFFFFFFFF,
				kOneHanded = 0x00000006,
				kTwoHanded = 0x00000007,
				kArchery = 0x00000008,
				kBlock = 0x00000009,
				kSmithing = 0x0000000A,
				kHeavyArmor = 0x0000000B,
				kLightArmor = 0x0000000C,
				kPickPocket = 0x0000000D,
				kLockPicking = 0x0000000E,
				kSneak = 0x0000000F,
				kAlchemy = 0x00000010,
				kSpeech = 0x00000011,
				kAlteration = 0x00000012,
				kConjuration = 0x00000013,
				kDestruction = 0x00000014,
				kIllusion = 0x00000015,
				kRestoration = 0x00000016,
				kEnchanting = 0x00000017
			};


			union Union
			{
				Skill		skill;
				SpellItem*	spell;
			};


			Flag GetSanitizedType();


			// members
			Flag	flags;		// 0
			Type	type;		// 1
			UInt16	pad02;		// 2
			UInt32	pad04;		// 4
			Union	teaches;	// 8
		};

		virtual ~TESObjectBOOK();																															// 00

		// override (TESBoundObject)
		virtual bool	LoadForm(TESFile* a_mod) override;																									// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;																						// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;																						// 0F
		virtual void	InitItem() override;																												// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, UInt32 a_arg5) override;	// 37
		virtual bool	GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst, bool a_unk) override;														// 4D

		bool	TeachesSkill() const;
		bool	TeachesSpell() const;
		bool	IsRead() const;
		bool	CanBeTaken() const;


		// members
		Data			data;			// 110
		TESObjectSTAT*	bookStat;		// 120
		TESDescription	bookText;		// 128
	};
	STATIC_ASSERT(sizeof(TESObjectBOOK) == 0x138);
}
