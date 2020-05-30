#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSIMusicType.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSMusicType :
		public TESForm,		 // 00
		public BSIMusicType	 // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMusicType;
		inline static constexpr auto FORMTYPE = FormType::MusicType;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSMusicType();  // 00

		// override (TESForm)
		virtual void		ClearData() override;						  // 05
		virtual bool		Load(TESFile* a_mod) override;				  // 06
		virtual void		InitItemImpl() override;					  // 13
		virtual const char* GetFormEditorID() const override;			  // 32 - { return editorID.c_str(); }
		virtual bool		SetFormEditorID(const char* a_str) override;  // 33 - { editorID = a_str; return true; }

		// override (BSIMusicType)
		virtual void DoUpdate() override;								 // 00
		virtual void DoPlay() override;									 // 01
		virtual void DoPause() override;								 // 02
		virtual void DoFinish(bool a_arg1) override;					 // 03
		virtual void DoApplyDuckingAttenuation(UInt16 a_arg1) override;	 // 04
		virtual void DoClearDucking() override;							 // 05
		virtual void DoPrepare() override;								 // 06


		// members
		BSFixedString formEditorID;	 // 70 - EDID
	};
	STATIC_ASSERT(sizeof(BGSMusicType) == 0x78);
}
