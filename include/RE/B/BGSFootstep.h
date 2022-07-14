#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSFootstep : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSFootstep;
		inline static constexpr auto VTABLE = VTABLE_BGSFootstep;
		inline static constexpr auto FORMTYPE = FormType::Footstep;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSFootstep() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		BSFixedString     tag;        // 20 - ANAM
		BGSImpactDataSet* impactSet;  // 28 - DATA
	};
	static_assert(sizeof(BGSFootstep) == 0x30);
}
