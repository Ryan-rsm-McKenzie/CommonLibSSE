#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSProcedureTreeSequence

#include "RE/BGSProcedureTreeBranch.h"  // BGSProcedureTreeBranch
#include "RE/BGSTypedItem.h"  // BGSTypedItem


namespace RE
{
	class BGSProcedureTreeSequence : public BGSTypedItem<BGSProcedureTreeSequence, BGSProcedureTreeBranch>
	{
	public:
		inline static const void* RTTI = RTTI_BGSProcedureTreeSequence;


		virtual ~BGSProcedureTreeSequence();	// 00

		// override (BGSProcedureTreeBranch)
		virtual void	Unk_04(void) override;	// 04
		virtual void	Unk_06(void) override;	// 06
	};
	STATIC_ASSERT(sizeof(BGSProcedureTreeSequence) == 0x30);
}
