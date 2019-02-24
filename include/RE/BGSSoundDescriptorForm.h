#pragma once

#include "RE/BSISoundDescriptor.h"  // BSISoundDescriptor
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSStandardSoundDef;


	class BGSSoundDescriptorForm :
		public TESForm,				// 00
		public BSISoundDescriptor	// 20
	{
	public:
		enum { kTypeID = FormType::SoundRecord };


		virtual ~BGSSoundDescriptorForm();			// 00

		// override (TESForm)
		virtual bool	LoadForm(TESFile* a_mod);	// 06
		virtual void	InitItem();					// 13
		virtual bool	SetName(const char* a_str);	// 33

		// add
		virtual void	Unk_3B(void);				// 3B - calls some virtual function on standardSoundDef


		// members
		BGSStandardSoundDef* standardSoundDef;	// 28
	};
	STATIC_ASSERT(sizeof(BGSSoundDescriptorForm) == 0x30);
}
