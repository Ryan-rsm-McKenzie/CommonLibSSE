#pragma once

namespace RE
{
	class ImageSpaceEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_ImageSpaceEffect;

		virtual ~ImageSpaceEffect();  // 00

		// add
		virtual void Unk_01(void);  // 01
		virtual void Unk_02(void);  // 02 - { return; }
		virtual void Unk_03(void);  // 03 - { return; }
		virtual void Unk_04(void);  // 04 - { return; }
		virtual void Unk_05(void);  // 05 - { return; }
		virtual void Unk_06(void);  // 06
		virtual void Unk_07(void);  // 07 - { return 0; }
		virtual void Unk_08(void);  // 08 - { return 0; }
		virtual void Unk_09(void);  // 09 - { return 0; }

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
	};
	static_assert(sizeof(ImageSpaceEffect) == 0x90);
}
