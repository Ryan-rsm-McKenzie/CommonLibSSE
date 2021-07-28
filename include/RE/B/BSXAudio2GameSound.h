#pragma once

#include "RE/B/BSGameSound.h"
#include "RE/I/IXAudio2VoiceCallback.h"

namespace RE
{
	class BSXAudio2GameSound :
		public BSGameSound,           // 000
		public IXAudio2VoiceCallback  // 0C8
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSXAudio2GameSound;

		// override (BSGameSound)
		void Unk_00() override;  // 00

		~BSXAudio2GameSound() override;  // 01

		void Unk_04() override;  // 04
		void Unk_06() override;  // 06
		void Unk_07() override;  // 07
		void Unk_08() override;  // 08
		void Unk_09() override;  // 09
		void Unk_0A() override;  // 0A
		void Unk_0B() override;  // 0B
		void Unk_0C() override;  // 0C
		void Unk_0D() override;  // 0D
		void Unk_0E() override;  // 0E
		void Unk_0F() override;  // 0F
		void Unk_10() override;  // 10
		void Unk_11() override;  // 11
		void Unk_12() override;  // 12
		void Unk_13() override;  // 13
		void Unk_14() override;  // 14
		void Unk_15() override;  // 15
		void Unk_16() override;  // 16
		void Unk_17() override;  // 17
		void Unk_18() override;  // 18

		// members
		std::uint64_t unk0C8;  // 0C8
		std::uint64_t unk0D0;  // 0D0
		std::uint64_t unk0D8;  // 0D8
		std::uint64_t unk0E0;  // 0E0
		std::uint64_t unk0E8;  // 0E8
		std::uint64_t unk0F0;  // 0F0
		std::uint64_t unk0F8;  // 0F8
		std::uint64_t unk100;  // 100
		std::uint64_t unk108;  // 108
		std::uint64_t unk110;  // 110
		std::uint64_t unk118;  // 118
		std::uint64_t unk120;  // 120
		std::uint64_t unk128;  // 128
		std::uint64_t unk130;  // 130
		std::uint64_t unk138;  // 138
		std::uint64_t unk140;  // 140
		std::uint64_t unk148;  // 148
		std::uint64_t unk150;  // 150
		std::uint64_t unk158;  // 158
		std::uint64_t unk160;  // 160
		std::uint64_t unk168;  // 168
		std::uint64_t unk170;  // 170
		std::uint64_t unk178;  // 178
		std::uint64_t unk180;  // 180
		std::uint64_t unk188;  // 188
		std::uint64_t unk190;  // 190
		std::uint64_t unk198;  // 198
		std::uint64_t unk1A0;  // 1A0
		std::uint64_t unk1A8;  // 1A8
		std::uint64_t unk1B0;  // 1B0
		std::uint64_t unk1B8;  // 1B8
		std::uint64_t unk1C0;  // 1C0
		std::uint64_t unk1C8;  // 1C8
		std::uint64_t unk1D0;  // 1D0
		std::uint64_t unk1D8;  // 1D8
		std::uint64_t unk1E0;  // 1E0
		std::uint64_t unk1E8;  // 1E8
		std::uint64_t unk1F0;  // 1F0
		std::uint64_t unk1F8;  // 1F8
		std::uint64_t unk200;  // 200
		std::uint64_t unk208;  // 208
		std::uint64_t unk210;  // 210
		std::uint64_t unk218;  // 218
	};
	static_assert(sizeof(BSXAudio2GameSound) == 0x220);
}
