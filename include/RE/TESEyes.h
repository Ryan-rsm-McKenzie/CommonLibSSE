#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESEyes

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class TESEyes :
		public TESForm,		// 00
		public TESFullName,	// 20
		public TESTexture	// 30
	{
	public:
		inline static const void* RTTI = RTTI_TESEyes;


		enum { kTypeID = FormType::Eyes };


		enum class Flag : UInt8
		{
			kNone = 0,
			kPlayable = 1 << 0,
			kNotMale = 1 << 1,
			kNotFemale = 1 << 2
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESEyes();									// 00

		// override (TESForm)
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06 - { return true; }


		// members
		Flag	flags;	// 40 - DATA
		UInt8	pad41;	// 41
		UInt16	pad42;	// 42
		UInt32	pad44;	// 44
	};
	STATIC_ASSERT(sizeof(TESEyes) == 0x48);
}
