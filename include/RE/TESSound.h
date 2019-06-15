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


		virtual ~TESSound();								// 00

		// override (TESBoundAnimObject)
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem();							// 13
		virtual bool	SetName(const char* a_str);			// 33


		// members
		BGSSoundDescriptorForm* soundDescriptor;	// 30 - SDSC
	};
	STATIC_ASSERT(sizeof(TESSound) == 0x38);
}
