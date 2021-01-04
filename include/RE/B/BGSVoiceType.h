#pragma once

#include "RE/B/BSString.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	struct VOICE_TYPE_DATA	// DNAM
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kAllowDefaultDialogue = 1 << 0,
			kFemale = 1 << 1
		};

		// members
		stl::enumeration<Flag, std::uint8_t> flags;	 // 0
	};
	static_assert(sizeof(VOICE_TYPE_DATA) == 0x1);

	class BGSVoiceType : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSVoiceType;
		inline static constexpr auto FORMTYPE = FormType::VoiceType;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
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
		std::uint8_t	pad21;		   // 21
		std::uint16_t	pad22;		   // 22
		std::uint16_t	pad24;		   // 24
		BSString		formEditorID;  // 28 - EDID
	};
	static_assert(sizeof(BGSVoiceType) == 0x38);
}
