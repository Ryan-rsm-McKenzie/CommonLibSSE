#pragma once

#include "skse64/GameFormComponents.h"  // TESFullName, TESModelTextureSwap, TESIcon, TESValueForm, TESWeightForm, TESDescription, BGSDestructibleObjectForm, BGSMessageIcon, BGSPickupPutdownSounds, BGSKeywordForm
#include "skse64/GameObjects.h"  // TESObjectBOOK

#include "RE/TESBoundObject.h"  // TESBoundObject

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
		enum { kTypeID = kFormType_Book };


		struct Data
		{
			enum
			{
				kType_None			= 0,
				kType_Skill			= 1 << 0,
				kType_CantBeTaken	= 1 << 1,
				kType_Spell			= 1 << 2,	// takes priority over skill
				kType_Read			= 1 << 3,	// set once the book is equipped by the player, along with the CHANGE_BOOK_READ (0x40) change flag
			};

			UInt8	flags;		// 0
			UInt8	type;		// 1
			UInt16	unk02;		// 2, probably padding too
			UInt32	unk04;		// 4, probably padding (SE)

			union
			{
				UInt32		skill;
				SpellItem*	spell;
			} teaches;			// 8

			// make some sense of the flags field so we know what's in the union
			UInt32	GetSanitizedType();
		};


		bool IsRead() const;


		// members
		Data			data;			// 110
		TESObjectSTAT*	bookStat;		// 120
		TESDescription	description2;	// 128
	};

	STATIC_ASSERT(sizeof(TESObjectBOOK) == 0x138);
}
