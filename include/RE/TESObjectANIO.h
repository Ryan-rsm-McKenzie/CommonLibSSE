#pragma once

#include "RE/BSString.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESModelTextureSwap.h"


namespace RE
{
	class TESObjectANIO :
		public TESForm,				// 00
		public TESModelTextureSwap	// 20
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectANIO;


		enum { kTypeID = FormType::AnimatedObject };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESObjectANIO();											// 00

		// override (TESForm)
		virtual bool		Load(TESFile* a_mod) override;					// 06
		virtual void		InitItemImpl() override;						// 13
		virtual const char*	GetFormEditorID() override;						// 32 - { return editorID.c_str(); }
		virtual bool		SetFormEditorID(const char* a_str) override;	// 33 - { editorID = a_str; }


		// members
		BSFixedString	editorID;		// 58 - EDID
		BSFixedString	unloadEvent;	// 60 - BNAM
	};
	STATIC_ASSERT(sizeof(TESObjectANIO) == 0x68);
}
