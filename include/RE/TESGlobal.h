#pragma once

#include "RE/BSString.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class TESGlobal : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESGlobal;
		inline static constexpr auto FORMTYPE = FormType::Global;


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


		virtual ~TESGlobal();  // 00

		// override (TESform)
		virtual bool		Load(TESFile* a_mod) override;				  // 06
		virtual const char* GetFormEditorID() const override;			  // 32 - { return formEditorID.c_str(); }
		virtual bool		SetFormEditorID(const char* a_str) override;  // 33 - { formEditorID = a_str; return true; }


		// members
		BSString formEditorID;	// 20 - EDID
		Type	 type;			// 30 - ENAM
		UInt8	 pad31;			// 31
		UInt16	 pad32;			// 32
		float	 value;			// 34 - FLTV
	};
	STATIC_ASSERT(sizeof(TESGlobal) == 0x38);
}
