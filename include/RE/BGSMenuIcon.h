#pragma once

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESIcon.h"  // TESIcon


namespace RE
{
	class BGSMenuIcon :
		public TESForm,	// 00
		public TESIcon	// 20
	{
	public:
		enum { kTypeID = FormType::MenuIcon };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~BGSMenuIcon();							// 00

		// override (TESForm)
		virtual bool LoadForm(TESFile* a_mod) override;	// 06 - { return true; }
	};
	STATIC_ASSERT(sizeof(BGSMenuIcon) == 0x30);
}
