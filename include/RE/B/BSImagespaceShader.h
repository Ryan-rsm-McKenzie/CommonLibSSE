#pragma once

#include "RE/B/BSShader.h"
#include "RE/I/ImageSpaceEffect.h"

namespace RE
{
	class BSImagespaceShader :
		public BSShader,         // 000
		public ImageSpaceEffect  // 090
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSImagespaceShader;

		~BSImagespaceShader() override;  // 00

		// override (BSShader)
		void Unk_02(void) override;  // 02
		void Unk_03(void) override;  // 03
		void Unk_06(void) override;  // 06
		void Unk_07(void) override;  // 07
		void Unk_09(void) override;  // 09

		// add
		virtual void Unk_0A(void);  // 0A - { return; }
		virtual void Unk_0B(void);  // 0B - { return; }
		virtual void Unk_0C(void);  // 0C
		virtual void Unk_0D(void);  // 0D
		virtual void Unk_0E(void);  // 0E

		// members
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
	};
	static_assert(sizeof(BSImagespaceShader) == 0x1A8);
}
