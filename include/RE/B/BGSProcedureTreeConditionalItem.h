#pragma once

#include "RE/I/IProcedureTreeItem.h"
#include "RE/T/TESCondition.h"

namespace RE
{
	class BGSProcedureTreeConditionalItem : public IProcedureTreeItem
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSProcedureTreeConditionalItem;

		~BGSProcedureTreeConditionalItem() override;  // 00

		// override (IProcedureTreeItem)
		void Unk_01(void) override;          // 01
		void Unk_02(void) override;          // 02
		void Load(TESFile* a_mod) override;  // 03
		void Unk_07(void) override;          // 07

		// members
		TESCondition conditions;  // 08
	};
	static_assert(sizeof(BGSProcedureTreeConditionalItem) == 0x10);
}
