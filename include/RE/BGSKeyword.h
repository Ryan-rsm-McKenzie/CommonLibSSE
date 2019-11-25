#pragma once

#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSKeyword : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSKeyword;


		enum { kTypeID = FormType::Keyword };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSKeyword();											// 00

		// override (TESForm)
		virtual bool		LoadForm(TESFile* a_mod) override;			// 06
		virtual const char*	GetEditorID() override;						// 32 - { return keyword.c_str(); }
		virtual bool		SetEditorID(const char* a_str) override;	// 33


		// members
		BSFixedString keyword;	// 20
	};
	STATIC_ASSERT(sizeof(BGSKeyword) == 0x28);
}
