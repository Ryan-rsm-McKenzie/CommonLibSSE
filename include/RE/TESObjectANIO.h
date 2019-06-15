#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESObjectANIO

#include "RE/BSString.h"  // BSString
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap


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


		virtual ~TESObjectANIO();										// 00

		// override (TESForm)
		virtual bool		LoadForm(TESFile* a_mod) override;			// 06
		virtual void		InitItem() override;						// 13
		virtual const char*	GetEditorID() override;						// 32 - { return editorID.empty() ? "" : editorID.c_str(); }
		virtual bool		SetEditorID(const char* a_str) override;	// 33


		// members
		BSFixedString	editorID;		// 58 - EDID
		BSFixedString	unloadEvent;	// 60 - BNAM
	};
	STATIC_ASSERT(sizeof(TESObjectANIO) == 0x68);
}
