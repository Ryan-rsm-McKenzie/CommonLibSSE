#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESGlobal

#include "RE/BSString.h"  // BSString
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class TESGlobal : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_TESGlobal;


		enum { kTypeID = FormType::Global };


		enum class Type : UInt8
		{
			kFloat = 'f',
			kLong = 'l',
			kShort = 's'
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kConstant = 1 << 6,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESGlobal();											// 00

		// override (TESform)
		virtual bool		LoadForm(TESFile* a_mod) override;			// 06
		virtual const char*	GetEditorID(void) override;					// 32 - { return editorID.c_str() ? editorID.c_str() : ""; }
		virtual bool		SetEditorID(const char* a_str) override;	// 33 - { editorID = a_str; return true; }


		// members
		BSString	editorID;	// 20 - EDID
		Type		type;		// 30 - ENAM
		UInt8		pad31;		// 31
		UInt16		pad32;		// 32
		float		value;		// 34 - FLTV
	};
	STATIC_ASSERT(sizeof(TESGlobal) == 0x38);
}
