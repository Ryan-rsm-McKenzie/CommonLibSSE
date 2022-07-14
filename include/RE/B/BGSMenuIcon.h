#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESIcon.h"

namespace RE
{
	class BGSMenuIcon :
		public TESForm,  // 00
		public TESIcon   // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMenuIcon;
		inline static constexpr auto VTABLE = VTABLE_BGSMenuIcon;
		inline static constexpr auto FORMTYPE = FormType::MenuIcon;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		~BGSMenuIcon() override;  // 00

		// override (TESForm)
		bool Load(TESFile* a_mod) override;  // 06 - { return true; }
	};
	static_assert(sizeof(BGSMenuIcon) == 0x30);
}
