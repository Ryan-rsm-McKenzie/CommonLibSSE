#pragma once

namespace RE
{
	class BSGameSound
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSGameSound;

		// add
		virtual void Unk_00();  // 00 - { return; }

		virtual ~BSGameSound();  // 01

		virtual void Unk_02();      // 02 - { return (unk5C >> 4) & 1; }
		virtual void Unk_03();      // 03
		virtual void Unk_04() = 0;  // 04
		virtual void Unk_05();      // 05
		virtual void Unk_06() = 0;  // 06
		virtual void Unk_07() = 0;  // 07
		virtual void Unk_08() = 0;  // 08
		virtual void Unk_09() = 0;  // 09
		virtual void Unk_0A() = 0;  // 0A
		virtual void Unk_0B();      // 0B - { unk5C |= 0x800; }
		virtual void Unk_0C();      // 0C
		virtual void Unk_0D() = 0;  // 0D
		virtual void Unk_0E();      // 0E
		virtual void Unk_0F() = 0;  // 0F
		virtual void Unk_10() = 0;  // 10
		virtual void Unk_11() = 0;  // 11
		virtual void Unk_12() = 0;  // 12
		virtual void Unk_13();      // 13 - { return; }
		virtual void Unk_14() = 0;  // 14
		virtual void Unk_15() = 0;  // 15
		virtual void Unk_16() = 0;  // 16
		virtual void Unk_17() = 0;  // 17
		virtual void Unk_18() = 0;  // 18

		// members
		std::uint64_t unk08;  // 08
		std::uint64_t unk10;  // 10
		std::uint64_t unk18;  // 18
		std::uint64_t unk20;  // 20
		std::uint64_t unk28;  // 28
		std::uint64_t unk30;  // 30
		std::uint64_t unk38;  // 38
		std::uint64_t unk40;  // 40
		std::uint64_t unk48;  // 48
		std::uint64_t unk50;  // 50
		std::uint64_t unk58;  // 58
		std::uint64_t unk60;  // 60
		std::uint64_t unk68;  // 68
		std::uint64_t unk70;  // 70
		std::uint64_t unk78;  // 78
		std::uint64_t unk80;  // 80
		std::uint64_t unk88;  // 88
		std::uint64_t unk90;  // 90
		std::uint64_t unk98;  // 98
		std::uint64_t unkA0;  // A0
		std::uint64_t unkA8;  // A8
		std::uint64_t unkB0;  // B0
		std::uint64_t unkB8;  // B8
		std::uint64_t unkC0;  // C0
	};
	static_assert(sizeof(BSGameSound) == 0xC8);
}
