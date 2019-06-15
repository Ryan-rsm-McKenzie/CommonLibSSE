#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSProcedureTreeBranch

#include "RE/BGSProcedureTreeConditionalItem.h"  // BGSProcedureTreeConditionalItem
#include "RE/BSTArray.h"  // BSTArray


namespace RE
{
	class BGSProcedureTreeBranch : public BGSProcedureTreeConditionalItem
	{
	public:
		inline static const void* RTTI = RTTI_BGSProcedureTreeBranch;


		virtual ~BGSProcedureTreeBranch();				// 00

		// override (BGSProcedureTreeConditionalItem)
		virtual void	Unk_01(void) override;			// 01
		virtual void	Unk_02(void) override;			// 02
		virtual void	Load(TESFile* a_mod) override;	// 03
		virtual void	Unk_05(void) override;			// 05
		virtual void	Unk_0A(void) override;			// 0A - { return 1; }
		virtual void	Unk_0B(void) override;			// 0B
		virtual void	Unk_0C(void) override;			// 0C
		virtual void	Unk_0D(void) override;			// 0D - { return 0; }
		virtual void	Unk_0E(void) override;			// 0E - { return; }
		virtual void	Unk_0F(void) override;			// 0F - { return 0; }
		virtual void	Unk_10(void) override;			// 10

		// add
		virtual void	Unk_11(void);					// 11

		// members
		BSTArray<BGSProcedureTreeConditionalItem*>	conditions;	// 10
		UInt64										unk28;		// 28
	};
	STATIC_ASSERT(sizeof(BGSProcedureTreeBranch) == 0x30);
}
