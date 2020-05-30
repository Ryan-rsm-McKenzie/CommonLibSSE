#pragma once

#include "RE/BSString.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	struct VOICE_TYPE_DATA	// DNAM
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kAllowDefaultDialogue = 1 << 0,
			kFemale = 1 << 1
		};


		Flag flags;	 // 0
	};
	STATIC_ASSERT(sizeof(VOICE_TYPE_DATA) == 0x1);


	class BGSVoiceType : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSVoiceType;
		inline static constexpr auto FORMTYPE = FormType::VoiceType;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSVoiceType();  // 00

		// override (TESForm)
		virtual bool		Load(TESFile* a_mod) override;				  // 06
		virtual const char* GetFormEditorID() const override;			  // 32 - { return formEditorID.c_str(); }
		virtual bool		SetFormEditorID(const char* a_str) override;  // 33 - { formEditorID = a_str; return true; }


		// members
		VOICE_TYPE_DATA data;		   // 20 - DNAM
		UInt8			pad21;		   // 21
		UInt16			pad22;		   // 22
		UInt16			pad24;		   // 24
		BSString		formEditorID;  // 28 - EDID
	};
	STATIC_ASSERT(sizeof(BGSVoiceType) == 0x38);
}
