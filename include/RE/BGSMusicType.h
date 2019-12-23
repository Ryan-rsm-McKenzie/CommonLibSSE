#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSIMusicType.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


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


		virtual ~BGSMusicType();											// 00

		// override (TESForm)
		virtual void		ClearData() override;							// 05
		virtual bool		Load(TESFile* a_mod) override;					// 06
		virtual void		InitItemImpl() override;						// 13
		virtual const char*	GetFormEditorID() override;						// 32 - { return editorID.c_str(); }
		virtual bool		SetFormEditorID(const char* a_str) override;	// 33 - { editorID = a_str; return true; }


		// members
		BSFixedString editorID;	// 70 - EDID
	};
	STATIC_ASSERT(sizeof(BGSMusicType) == 0x78);
}
