#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIMusicType.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSMusicType :
		public TESForm,      // 00
		public BSIMusicType  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMusicType;
		inline static constexpr auto VTABLE = VTABLE_BGSMusicType;
		inline static constexpr auto FORMTYPE = FormType::MusicType;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSMusicType() override;  // 00

		// override (TESForm)
		void        ClearData() override;                         // 05
		bool        Load(TESFile* a_mod) override;                // 06
		void        InitItemImpl() override;                      // 13
		const char* GetFormEditorID() const override;             // 32 - { return editorID.c_str(); }
		bool        SetFormEditorID(const char* a_str) override;  // 33 - { editorID = a_str; return true; }

		// override (BSIMusicType)
		void DoUpdate() override;                                       // 00
		void DoPlay() override;                                         // 01
		void DoPause() override;                                        // 02
		void DoFinish(bool a_arg1) override;                            // 03
		void DoApplyDuckingAttenuation(std::uint16_t a_arg1) override;  // 04
		void DoClearDucking() override;                                 // 05
		void DoPrepare() override;                                      // 06

		// members
		BSFixedString formEditorID;  // 70 - EDID
	};
	static_assert(sizeof(BGSMusicType) == 0x78);
}
