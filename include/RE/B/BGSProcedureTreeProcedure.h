#pragma once

#include "RE/B/BGSProcedureTreeConditionalItem.h"
#include "RE/B/BGSTypedItem.h"

namespace RE
{
	class BGSProcedureBase;

	class BGSProcedureTreeProcedure : public BGSTypedItem<BGSProcedureTreeProcedure, BGSProcedureTreeConditionalItem>
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSProcedureTreeProcedure;

		~BGSProcedureTreeProcedure() override;  // 00

		// override (BGSProcedureTreeConditionalItem)
		void Unk_01(void) override;          // 01
		void Unk_02(void) override;          // 02
		void Load(TESFile* a_mod) override;  // 03
		void Unk_04(void) override;          // 04
		void Unk_05(void) override;          // 05
		void Unk_06(void) override;          // 06
		void Unk_07(void) override;          // 07
		void Unk_08(void) override;          // 08
		void Unk_09(void) override;          // 09
		void Unk_0A(void) override;          // 0A
		void Unk_0B(void) override;          // 0B
		void Unk_0C(void) override;          // 0C
		void Unk_0D(void) override;          // 0D
		void Unk_0E(void) override;          // 0E
		void Unk_0F(void) override;          // 0F - { return 1; }
		void Unk_10(void) override;          // 10

		// members
		BGSProcedureBase* procedure;  // 10
	};
	static_assert(sizeof(BGSProcedureTreeProcedure) == 0x18);
}
