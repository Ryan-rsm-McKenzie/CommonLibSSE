#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class TESWordOfPower :
		public TESForm,     // 00
		public TESFullName  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESWordOfPower;
		inline static constexpr auto VTABLE = VTABLE_TESWordOfPower;
		inline static constexpr auto FORMTYPE = FormType::WordOfPower;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~TESWordOfPower() override;  // 00

		// override (TESForm)
		bool Load(TESFile* a_mod) override;  // 06

		// members
		BSFixedString translation;  // 30 - TNAM
	};
	static_assert(sizeof(TESWordOfPower) == 0x38);
}
