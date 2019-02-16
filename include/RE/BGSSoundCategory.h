#pragma once

#include "RE/BSISoundCategory.h"  // BSISoundCategory
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName


namespace RE
{
	class BGSSoundCategory :
		public TESForm,			// 00
		public TESFullName,		// 20
		public BSISoundCategory	// 30
	{
	public:
		enum { kTypeID = FormType::SoundCategory };


		virtual ~BGSSoundCategory();				// 00

		// override (TESForm)
		virtual void	InitDefaults();				// 04
		virtual bool	LoadForm(TESFile* a_mod);	// 06
		virtual void	InitItem();					// 13


		// members
		UInt32				flags;					// 38 - FNAM
		UInt32				unk3C;					// 3C
		BGSSoundCategory*	parent;					// 40 - SNCT
		UInt16				unk48;					// 48 - flag?
		UInt16				unk4A;					// 4A
		UInt16				staticVolumeMultiplier;	// 4C - VNAM
		UInt16				defaultMenuValue;		// 4E - UNAM
		float				ingameVolume;			// 50
		float				unk54;					// 54
	};
	STATIC_ASSERT(sizeof(BGSSoundCategory) == 0x58);
}
