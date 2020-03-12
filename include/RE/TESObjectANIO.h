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
		inline static constexpr auto RTTI = RTTI_TESObjectANIO;
		inline static constexpr auto FORMTYPE = FormType::AnimatedObject;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESObjectANIO();  // 00

		// override (TESForm)
		virtual bool		Load(TESFile* a_mod) override;				  // 06
		virtual void		InitItemImpl() override;					  // 13
		virtual const char* GetFormEditorID() const override;			  // 32 - { return formEditorID.c_str(); }
		virtual bool		SetFormEditorID(const char* a_str) override;  // 33 - { if (formEditorID == a_str) return false; formEditorID = a_str; return true; }


		// members
		BSFixedString formEditorID;		// 58 - EDID
		BSFixedString unloadEventName;	// 60 - BNAM
	};
	STATIC_ASSERT(sizeof(TESObjectANIO) == 0x68);
}
