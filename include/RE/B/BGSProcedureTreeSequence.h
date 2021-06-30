#pragma once

#include "RE/B/BGSProcedureTreeBranch.h"
#include "RE/B/BGSTypedItem.h"

namespace RE
{
	class BGSProcedureTreeSequence : public BGSTypedItem<BGSProcedureTreeSequence, BGSProcedureTreeBranch>
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSProcedureTreeSequence;

		~BGSProcedureTreeSequence() override;  // 00

		// override (BGSProcedureTreeBranch)
		void Unk_04(void) override;  // 04
		void Unk_06(void) override;  // 06
	};
	static_assert(sizeof(BGSProcedureTreeSequence) == 0x30);
}
