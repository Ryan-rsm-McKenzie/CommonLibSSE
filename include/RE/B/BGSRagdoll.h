#pragma once

#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class TESActorBase;

	class BGSRagdoll :
		public TESForm,  // 000
		public TESModel  // 020
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSRagdoll;
		inline static constexpr auto VTABLE = VTABLE_BGSRagdoll;
		inline static constexpr auto FORMTYPE = FormType::Ragdoll;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		~BGSRagdoll() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		std::uint64_t    unk048;  // 048
		std::uint64_t    unk050;  // 050
		std::uint64_t    unk058;  // 058
		std::uint64_t    unk060;  // 060
		std::uint64_t    unk068;  // 068
		std::uint64_t    unk070;  // 070
		std::uint64_t    unk078;  // 078
		std::uint64_t    unk080;  // 080
		std::uint64_t    unk088;  // 088
		std::uint64_t    unk090;  // 090
		BSTArray<void*>  unk098;  // 098
		std::uint64_t    unk0B0;  // 0B0
		std::uint64_t    unk0B8;  // 0B8
		std::uint64_t    unk0C0;  // 0C0
		std::uint64_t    unk0C8;  // 0C8
		BSTArray<void*>  unk0D0;  // 0D0
		BSTArray<void*>  unk0E8;  // 0E8
		std::uint64_t    unk100;  // 100
		BSTArray<void*>  unk108;  // 108
		BSTArray<void*>  unk120;  // 120
		std::uint64_t    unk138;  // 138
		BSTArray<void*>  unk140;  // 140
		BSTArray<void*>  unk158;  // 158
		std::uint64_t    unk170;  // 170
		std::uint64_t    unk178;  // 178
		std::uint64_t    unk180;  // 180
		std::uint64_t    unk188;  // 188
		std::uint64_t    unk190;  // 190
		std::uint64_t    unk198;  // 198
		std::uint64_t    unk1A0;  // 1A0
		BGSBodyPartData* unk1A8;  // 1A8
		TESActorBase*    unk1B0;  // 1B0
	};
	static_assert(sizeof(BGSRagdoll) == 0x1B8);
}
