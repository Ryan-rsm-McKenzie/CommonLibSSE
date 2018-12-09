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
			enum Flag : UInt8
			{
				kNone = 0,
				kSkill = 1 << 0,
				kCantBeTaken = 1 << 1,
				kSpell = 1 << 2,		// takes priority over skill
				kRead = 1 << 3,			// set once the book is equipped by the player, along with the CHANGE_BOOK_READ (0x40) change flag
			};


			union Union
			{
				UInt32		skill;
				SpellItem*	spell;
			};


			Flag GetSanitizedType();


			// members
			Flag	flags;		// 0
			UInt8	type;		// 1
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
		TESDescription	description2;	// 128
	};
	STATIC_ASSERT(sizeof(TESObjectBOOK) == 0x138);
}
