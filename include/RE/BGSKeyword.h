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


		virtual ~BGSKeyword();												// 00

		// override (TESForm)
		virtual bool		Load(TESFile* a_mod) override;					// 06
		virtual const char*	GetFormEditorID() const override;				// 32 - { return formEditorID.c_str(); }
		virtual bool		SetFormEditorID(const char* a_str) override;	// 33 - { formEditorID = a_str; }


		// members
		BSFixedString formEditorID;	// 20
	};
	STATIC_ASSERT(sizeof(BGSKeyword) == 0x28);
}
