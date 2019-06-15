#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSMusicType

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSIMusicType.h"  // BSIMusicType
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSMusicType :
		public TESForm,		// 00
		public BSIMusicType	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSMusicType;


		enum { kTypeID = FormType::MusicType };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSMusicType();										// 00

		// override (TESForm)
		virtual void		ReleaseManagedData() override;				// 05
		virtual bool		LoadForm(TESFile* a_mod) override;			// 06
		virtual void		InitItem() override;						// 13
		virtual const char*	GetEditorID() override;						// 32 - { return editorID.empty() ? "" : editorID.c_str(); }
		virtual bool		SetEditorID(const char* a_str) override;	// 33 - { editorID = a_str; return true; }


		// members
		BSFixedString editorID;	// 70 - EDID
	};
	STATIC_ASSERT(sizeof(BGSMusicType) == 0x78);
}
