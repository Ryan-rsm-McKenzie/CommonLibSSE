#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSSoundDescriptorForm

#include "RE/BSISoundDescriptor.h"  // BSISoundDescriptor
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSSoundDescriptor;


	class BGSSoundDescriptorForm :
		public TESForm,				// 00
		public BSISoundDescriptor	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSSoundDescriptorForm;


		enum { kTypeID = FormType::SoundRecord };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSSoundDescriptorForm();							// 00

		// override (TESForm)
		virtual void	ReleaseManagedData() override;				// 05
		virtual bool	LoadForm(TESFile* a_mod) override;			// 06
		virtual void	InitItem() override;						// 13
		virtual bool	SetEditorID(const char* a_str) override;	// 33

		// add
		virtual UInt32	GetDescriptorType();						// 3B - { return soundDescriptor->GetType(); }


		// members
		BGSSoundDescriptor* soundDescriptor;	// 28
	};
	STATIC_ASSERT(sizeof(BGSSoundDescriptorForm) == 0x30);
}
