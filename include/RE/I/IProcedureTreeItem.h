#pragma once

namespace RE
{
	class TESFile;

	class IProcedureTreeItem
	{
	public:
		inline static constexpr auto RTTI = RTTI_IProcedureTreeItem;

		virtual ~IProcedureTreeItem();  // 00

		// add
		virtual void Unk_01(void) = 0;          // 01
		virtual void Unk_02(void) = 0;          // 02
		virtual void Load(TESFile* a_mod) = 0;  // 03
		virtual void Unk_04(void) = 0;          // 04
		virtual void Unk_05(void) = 0;          // 05
		virtual void Unk_06(void) = 0;          // 06
		virtual void Unk_07(void) = 0;          // 07
		virtual void Unk_08(void);              // 08
		virtual void Unk_09(void);              // 09
		virtual void Unk_0A(void) = 0;          // 0A
		virtual void Unk_0B(void) = 0;          // 0B
		virtual void Unk_0C(void) = 0;          // 0C
		virtual void Unk_0D(void) = 0;          // 0D
		virtual void Unk_0E(void) = 0;          // 0E
		virtual void Unk_0F(void) = 0;          // 0F
		virtual void Unk_10(void) = 0;          // 10
	};
	static_assert(sizeof(IProcedureTreeItem) == 0x8);
}
