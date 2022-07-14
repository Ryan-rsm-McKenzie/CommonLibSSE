#pragma once

#include "RE/B/BSLight.h"
#include "RE/N/NiPlane.h"

namespace RE
{
	class BSShadowLight : public BSLight
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSShadowLight;

		struct Data
		{
			std::uint8_t  unk0[64];   // 00
			std::uint64_t unk40;      // 40
			std::uint64_t unk48;      // 48
			std::uint64_t unk50;      // 50
			std::uint32_t unk58;      // 58
			NiPlane       planes[6];  // 5C
			std::uint32_t unkBC;      // BC
			std::uint32_t unkC0;      // C0
			std::uint32_t unkC4;      // C4
			std::uint32_t unkCC;      // CC
			std::uint64_t unkD0;      // D4
			std::uint32_t unkDC;      // DC
			std::uint64_t unkE0;      // E0
			std::uint16_t unkE8;      // E8
		};
		static_assert(sizeof(Data) == 0xF0);

		~BSShadowLight() override;  // 00

		// add
		virtual void Unk_04();      // 04
		virtual void Unk_05();      // 05
		virtual void Unk_06();      // 06
		virtual void Unk_07();      // 07
		virtual void Unk_08();      // 08
		virtual void Unk_09() = 0;  // 09
		virtual void Unk_0A() = 0;  // 0A
		virtual void Unk_0B();      // 0B
		virtual void Unk_0C();      // 0C
		virtual void Unk_0D();      // 0D
		virtual void Unk_0E();      // 0E
		virtual void Unk_0F();      // 0F
		virtual void Unk_10() = 0;  // 10

		// members
		std::uint32_t   unk140;           // 140
		std::uint32_t   unk144;           // 144
		BSTArray<void*> unk148;           // 148
		Data            unk160[4];        // 161
		std::uint32_t   unk520;           // 520
		std::uint32_t   unk524;           // 524
		BSTArray<void*> unk528;           // 528
		float           shadowBiasScale;  // 540
		std::uint32_t   unk544;           // 544
		std::uint32_t   unk548;           // 548
		std::uint32_t   unk54C;           // 54C
		std::uint64_t   unk550;           // 550
		std::uint8_t    unk558;           // 558
		std::uint8_t    pad559;           // 559
		std::uint8_t    pad55A;           // 55A
		std::uint32_t   pad55B;           // 55B
	};
	static_assert(sizeof(BSShadowLight) == 0x560);
}
