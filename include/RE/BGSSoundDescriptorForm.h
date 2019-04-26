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


		virtual ~BGSSoundDescriptorForm();							// 00

		// override (TESForm)
		virtual void	ReleaseManagedData() override;				// 05
		virtual bool	LoadForm(TESFile* a_mod) override;			// 06
		virtual void	InitItem() override;						// 13
		virtual bool	SetEditorID(const char* a_str) override;	// 33

		// add
		virtual void	Unk_3B(void);								// 3B - { return standardSoundDef->Unk_05(); }


		// members
		BGSStandardSoundDef* standardSoundDef;	// 28
	};
	STATIC_ASSERT(sizeof(BGSSoundDescriptorForm) == 0x30);
}
