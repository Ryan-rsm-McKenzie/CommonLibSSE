#pragma once

#include "RE/BGSProcedureTreeBranch.h"  // BGSProcedureTreeBranch
#include "RE/BGSTypedItem.h"  // BGSTypedItem


namespace RE
{
	class BGSProcedureTreeSequence : public BGSTypedItem<BGSProcedureTreeSequence, BGSProcedureTreeBranch>
	{
	public:
		virtual ~BGSProcedureTreeSequence();	// 00

		// override (BGSProcedureTreeBranch)
		virtual void	Unk_04(void) override;	// 04
		virtual void	Unk_06(void) override;	// 06
	};
	STATIC_ASSERT(sizeof(BGSProcedureTreeSequence) == 0x30);
}