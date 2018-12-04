#pragma once

#include "skse64/GameFormComponents.h"  // TESFullName, TESModelTextureSwap, TESIcon, TESValueForm, TESWeightForm, BGSDestructibleObjectForm, BGSMessageIcon, BGSPickupPutdownSounds

#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/TESBoundObject.h"  // TESBoundObject


namespace RE
{
	class TESObjectMISC :
		public TESBoundObject,				// 00
		public TESFullName,					// 30
		public TESModelTextureSwap,			// 40
		public TESIcon,						// 78
		public TESValueForm,				// 88
		public TESWeightForm,				// 98
		public BGSDestructibleObjectForm,	// A8
		public BGSMessageIcon,				// B8
		public BGSPickupPutdownSounds,		// D0
		public BGSKeywordForm				// E8
	{
	public:
		enum { kTypeID = FormType::Misc };


		// add
		virtual void	Unk_52(void);
		virtual void	Unk_53(void);
		virtual void	Unk_54(void);
	};
	STATIC_ASSERT(sizeof(TESObjectMISC) == 0x100);
}
