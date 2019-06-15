#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSVoiceType

#include "RE/BSString.h"  // BSString
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSVoiceType : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSVoiceType;


		enum { kTypeID = FormType::VoiceType };


		enum class Flag : UInt8
		{
			kNone = 0,
			kAllowDefaultDialogue = 1 << 0,
			kFemale = 1 << 1
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSVoiceType();											// 00

		// override (TESForm)
		virtual bool			LoadForm(TESFile* a_mod) override;			// 06
		virtual const char*		GetEditorID() override;						// 32 - { return editorID.empty() ? "" : editorID.c_str(); }
		virtual bool			SetEditorID(const char* a_str) override;	// 33 - { editorID = a_str; return true; }


		// members
		Flag		flags;		// 20 - DNAM
		UInt8		pad21;		// 21
		UInt16		pad22;		// 22
		UInt16		pad24;		// 24
		BSString	editorID;	// 28 - EDID
	};
	STATIC_ASSERT(sizeof(BGSVoiceType) == 0x38);
}
