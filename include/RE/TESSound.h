#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESSound

#include "RE/FormTypes.h"  // FormType, BGSSoundDescriptorForm
#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject


namespace RE
{
	class TESSound : public TESBoundAnimObject
	{
	public:
		inline static const void* RTTI = RTTI_TESSound;


		enum { kTypeID = FormType::Sound };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESSound();										// 00

		// override (TESBoundAnimObject)
		virtual void	InitDefaults() override;					// 04
		virtual bool	LoadForm(TESFile* a_mod) override;			// 06
		virtual void	InitItem() override;						// 13
		virtual bool	SetEditorID(const char* a_str) override;	// 33
		virtual void	Unk_41(void) override;						// 41
		virtual void	Unk_4A(void) override;						// 4A - { return 0; }


		// members
		BGSSoundDescriptorForm* soundDescriptor;	// 30 - SDSC
	};
	STATIC_ASSERT(sizeof(TESSound) == 0x38);
}
