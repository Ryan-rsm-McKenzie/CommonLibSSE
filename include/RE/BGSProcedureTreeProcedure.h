#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSProcedureTreeProcedure

#include "RE/BGSProcedureTreeConditionalItem.h"  // BGSProcedureTreeConditionalItem
#include "RE/BGSTypedItem.h"  // BGSTypedItem


namespace RE
{
	class BGSProcedureBase;


	class BGSProcedureTreeProcedure : public BGSTypedItem<BGSProcedureTreeProcedure, BGSProcedureTreeConditionalItem>
	{
	public:
		inline static const void* RTTI = RTTI_BGSProcedureTreeProcedure;


		virtual ~BGSProcedureTreeProcedure();			// 00

		// override (BGSProcedureTreeConditionalItem)
		virtual void	Unk_01(void) override;			// 01
		virtual void	Unk_02(void) override;			// 02
		virtual void	Load(TESFile* a_mod) override;	// 03
		virtual void	Unk_04(void) override;			// 04
		virtual void	Unk_05(void) override;			// 05
		virtual void	Unk_06(void) override;			// 06
		virtual void	Unk_07(void) override;			// 07
		virtual void	Unk_08(void) override;			// 08
		virtual void	Unk_09(void) override;			// 09
		virtual void	Unk_0A(void) override;			// 0A
		virtual void	Unk_0B(void) override;			// 0B
		virtual void	Unk_0C(void) override;			// 0C
		virtual void	Unk_0D(void) override;			// 0D
		virtual void	Unk_0E(void) override;			// 0E
		virtual void	Unk_0F(void) override;			// 0F - { return 1; }
		virtual void	Unk_10(void) override;			// 10


		// members
		BGSProcedureBase* procedure;	// 10
	};
	STATIC_ASSERT(sizeof(BGSProcedureTreeProcedure) == 0x18);
}
