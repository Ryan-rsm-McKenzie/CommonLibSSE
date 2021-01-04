#pragma once

#include "RE/B/BGSProcedureTreeConditionalItem.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSProcedureTreeBranch : public BGSProcedureTreeConditionalItem
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSProcedureTreeBranch;

		virtual ~BGSProcedureTreeBranch();	// 00

		// override (BGSProcedureTreeConditionalItem)
		virtual void Unk_01(void) override;			 // 01
		virtual void Unk_02(void) override;			 // 02
		virtual void Load(TESFile* a_mod) override;	 // 03
		virtual void Unk_05(void) override;			 // 05
		virtual void Unk_0A(void) override;			 // 0A - { return 1; }
		virtual void Unk_0B(void) override;			 // 0B
		virtual void Unk_0C(void) override;			 // 0C
		virtual void Unk_0D(void) override;			 // 0D - { return 0; }
		virtual void Unk_0E(void) override;			 // 0E - { return; }
		virtual void Unk_0F(void) override;			 // 0F - { return 0; }
		virtual void Unk_10(void) override;			 // 10

		// add
		virtual void Unk_11(void);	// 11

		// members
		BSTArray<BGSProcedureTreeConditionalItem*> conditions;	// 10
		std::uint64_t							   unk28;		// 28
	};
	static_assert(sizeof(BGSProcedureTreeBranch) == 0x30);
}
