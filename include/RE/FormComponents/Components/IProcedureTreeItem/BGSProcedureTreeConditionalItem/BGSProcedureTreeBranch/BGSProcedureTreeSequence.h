#pragma once

#include "RE/FormComponents/Components/IProcedureTreeItem/BGSProcedureTreeConditionalItem/BGSProcedureTreeBranch/BGSProcedureTreeBranch.h"
#include "RE/FormComponents/Components/BGSTypedItem.h"


namespace RE
{
	class BGSProcedureTreeSequence : public BGSTypedItem<BGSProcedureTreeSequence, BGSProcedureTreeBranch>
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSProcedureTreeSequence;


		virtual ~BGSProcedureTreeSequence();  // 00

		// override (BGSProcedureTreeBranch)
		virtual void Unk_04(void) override;	 // 04
		virtual void Unk_06(void) override;	 // 06
	};
	STATIC_ASSERT(sizeof(BGSProcedureTreeSequence) == 0x30);
}
