#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSKeyword : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSKeyword;
		inline static constexpr auto VTABLE = VTABLE_BGSKeyword;
		inline static constexpr auto FORMTYPE = FormType::Keyword;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSKeyword() override;  // 00

		// override (TESForm)
		bool        Load(TESFile* a_mod) override;                // 06
		const char* GetFormEditorID() const override;             // 32 - { return formEditorID.c_str(); }
		bool        SetFormEditorID(const char* a_str) override;  // 33 - { formEditorID = a_str; }

		// members
		BSFixedString formEditorID;  // 20
	};
	static_assert(sizeof(BGSKeyword) == 0x28);
}
