#pragma once

#include "RE/B/BSString.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModelTextureSwap.h"

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
			enum RecordFlag : std::uint32_t
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
	static_assert(sizeof(TESObjectANIO) == 0x68);
}
