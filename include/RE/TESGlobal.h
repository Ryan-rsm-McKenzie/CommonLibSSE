#pragma once

#include "RE/BSString.h"  // BSString
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class TESGlobal : public TESForm
	{
	public:
		enum { kTypeID = (UInt32)FormType::Global };


		enum class Type : UInt8
		{
			kFloat = 102,
			kLong = 108,
			kShort = 115
		};


		virtual ~TESGlobal();										// 00

		// override (TESform)
		virtual bool		LoadForm(TESFile* a_mod) override;		// 06
		virtual const char*	GetName(void) override;					// 32
		virtual bool		SetName(const char* a_str) override;	// 33


		// members
		BSString	editorID;	// 20 - EDID
		Type		type;		// 30 - ENAM
		UInt8		pad31;		// 31
		UInt16		pad32;		// 32
		float		value;		// 34 - FLTV
	};
	STATIC_ASSERT(sizeof(TESGlobal) == 0x38);
}
