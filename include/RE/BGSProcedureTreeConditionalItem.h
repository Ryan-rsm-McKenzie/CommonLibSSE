#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSProcedureTreeConditionalItem

#include "RE/Condition.h"  // Condition
#include "RE/IProcedureTreeItem.h"  // IProcedureTreeItem


namespace RE
{
	class BGSProcedureTreeConditionalItem : public IProcedureTreeItem
	{
	public:
		inline static const void* RTTI = RTTI_BGSProcedureTreeConditionalItem;


		virtual ~BGSProcedureTreeConditionalItem();		// 00

		// override (IProcedureTreeItem)
		virtual void	Unk_01(void) override;			// 01
		virtual void	Unk_02(void) override;			// 02
		virtual void	Load(TESFile* a_mod) override;	// 03
		virtual void	Unk_07(void) override;			// 07


		// members
		Condition conditions;	// 08
	};
	STATIC_ASSERT(sizeof(BGSProcedureTreeConditionalItem) == 0x10);
}
