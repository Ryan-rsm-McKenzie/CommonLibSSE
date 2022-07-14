#pragma once

#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	struct ACTOR_MOVEMENT_TYPES
	{
		enum ACTOR_MOVEMENT_TYPE : std::uint32_t
		{
			kWalk = 0,
			kRun = 1,
			kSneak = 2,
			kBleedout = 3,
			kSwim = 4,

			kTotal = 5
		};
	};
	using ACTOR_MOVEMENT_TYPE = ACTOR_MOVEMENT_TYPES::ACTOR_MOVEMENT_TYPE;

	class BGSFootstepSet : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSFootstepSet;
		inline static constexpr auto VTABLE = VTABLE_BGSFootstepSet;
		inline static constexpr auto FORMTYPE = FormType::FootstepSet;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSFootstepSet() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		BSTArray<BGSFootstep*> entries[ACTOR_MOVEMENT_TYPES::kTotal];  // 20
	};
	static_assert(sizeof(BGSFootstepSet) == 0x98);
}
