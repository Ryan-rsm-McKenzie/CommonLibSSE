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
		virtual void Unk_01() = 0;          // 01
		virtual void Unk_02() = 0;          // 02
		virtual void Load(TESFile* a_mod) = 0;  // 03
		virtual void Unk_04() = 0;          // 04
		virtual void Unk_05() = 0;          // 05
		virtual void Unk_06() = 0;          // 06
		virtual void Unk_07() = 0;          // 07
		virtual void Unk_08();              // 08
		virtual void Unk_09();              // 09
		virtual void Unk_0A() = 0;          // 0A
		virtual void Unk_0B() = 0;          // 0B
		virtual void Unk_0C() = 0;          // 0C
		virtual void Unk_0D() = 0;          // 0D
		virtual void Unk_0E() = 0;          // 0E
		virtual void Unk_0F() = 0;          // 0F
		virtual void Unk_10() = 0;          // 10
	};
	static_assert(sizeof(IProcedureTreeItem) == 0x8);
}
