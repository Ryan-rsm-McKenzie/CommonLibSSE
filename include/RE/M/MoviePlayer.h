#pragma once

namespace RE
{
	class MoviePlayer
	{
	public:
		inline static constexpr auto RTTI = RTTI_MoviePlayer;

		virtual ~MoviePlayer();  // 00

		// add
		virtual void Unk_01() = 0;  // 01
		virtual void Unk_02() = 0;  // 02
		virtual void Unk_03() = 0;  // 03
		virtual void Unk_04() = 0;  // 04
		virtual void Unk_05() = 0;  // 05
		virtual void Unk_06() = 0;  // 06
		virtual void Unk_07() = 0;  // 07
		virtual void Unk_08() = 0;  // 08
		virtual void Unk_09() = 0;  // 09
		virtual void Unk_0A() = 0;  // 0A
		virtual void Unk_0B() = 0;  // 0B
		virtual void Unk_0C() = 0;  // 0C
		virtual void Unk_0D();      // 0D

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
	};
	static_assert(sizeof(MoviePlayer) == 0x58);
}
