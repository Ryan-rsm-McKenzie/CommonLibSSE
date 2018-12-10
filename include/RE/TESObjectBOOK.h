#pragma once

#include "skse64/GameFormComponents.h"  // TESModelTextureSwap, TESIcon, TESValueForm, TESWeightForm, TESDescription, BGSDestructibleObjectForm, BGSMessageIcon, BGSPickupPutdownSounds

#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap

#include "Utility.h"  // MAKE_BITWISE_OPERATORS

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
				kSkill = 1 << 0,
				kCantBeTaken = 1 << 1,
				kSpell = 1 << 2,		// takes priority over skill
				kRead = 1 << 3,			// set once the book is equipped by the player, along with the CHANGE_BOOK_READ (0x40) change flag
			};

			MAKE_BITWISE_OPERATORS(Flag);


			enum class Type : UInt8
			{
				kBookTome = 0x00,
				kBookNote = 0xFF
			};

			MAKE_BITWISE_OPERATORS(Type);


			enum class Skill : UInt32
			{
				kOneHanded = 0x6,
				kTwoHanded = 0x7,
				kArchery = 0x8,
				kBlock = 0x9,
				kSmithing = 0xA,
				kHeavyArmor = 0xB,
				kLightArmor = 0xC,
				kPickPocket = 0xD,
				kLockPicking = 0xE,
				kSneak = 0xF,
				kAlchemy = 0x10,
				kSpeech = 0x11,
				kAlteration = 0x12,
				kConjuration = 0x13,
				kDestruction = 0x14,
				kIllusion = 0x15,
				kRestoration = 0x16,
				kEnchanting = 0x17
			};

			MAKE_BITWISE_OPERATORS(Skill);


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

		virtual ~TESObjectBOOK();																																		// 00

		// override (TESBoundObject)
		virtual bool	LoadForm(TESFile* a_mod) override;																												// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;																									// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;																									// 0F
		virtual void	InitItem() override;																															// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, uintptr_t a_arg3, uintptr_t a_arg4, uintptr_t a_arg5) override;	// 37
		virtual bool	GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst, bool a_unk) override;																	// 4D

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
