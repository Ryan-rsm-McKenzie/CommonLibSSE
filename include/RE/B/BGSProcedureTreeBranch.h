#pragma once

#include "RE/B/BGSProcedureTreeConditionalItem.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSProcedureTreeBranch : public BGSProcedureTreeConditionalItem
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSProcedureTreeBranch;

		~BGSProcedureTreeBranch() override;  // 00

		// override (BGSProcedureTreeConditionalItem)
		void Unk_01(void) override;          // 01
		void Unk_02(void) override;          // 02
		void Load(TESFile* a_mod) override;  // 03
		void Unk_05(void) override;          // 05
		void Unk_0A(void) override;          // 0A - { return 1; }
		void Unk_0B(void) override;          // 0B
		void Unk_0C(void) override;          // 0C
		void Unk_0D(void) override;          // 0D - { return 0; }
		void Unk_0E(void) override;          // 0E - { return; }
		void Unk_0F(void) override;          // 0F - { return 0; }
		void Unk_10(void) override;          // 10

		// add
		virtual void Unk_11(void);  // 11

		// members
		BSTArray<BGSProcedureTreeConditionalItem*> conditions;  // 10
		std::uint64_t                              unk28;       // 28
	};
	static_assert(sizeof(BGSProcedureTreeBranch) == 0x30);
}
