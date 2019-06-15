#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSXAudio2GameSound

#include "RE/BSGameSound.h"  // BSGameSound
#include "RE/IXAudio2VoiceCallback.h"  // IXAudio2VoiceCallback


namespace RE
{
	class BSXAudio2GameSound :
		public BSGameSound,				// 000
		public IXAudio2VoiceCallback	// 0C8
	{
	public:
		inline static const void* RTTI = RTTI_BSXAudio2GameSound;


		// override (BSGameSound)
		virtual void	Unk_00(void) override;	// 00

		virtual ~BSXAudio2GameSound();			// 01

		virtual void	Unk_04(void) override;	// 04
		virtual void	Unk_06(void) override;	// 06
		virtual void	Unk_07(void) override;	// 07
		virtual void	Unk_08(void) override;	// 08
		virtual void	Unk_09(void) override;	// 09
		virtual void	Unk_0A(void) override;	// 0A
		virtual void	Unk_0B(void) override;	// 0B
		virtual void	Unk_0C(void) override;	// 0C
		virtual void	Unk_0D(void) override;	// 0D
		virtual void	Unk_0E(void) override;	// 0E
		virtual void	Unk_0F(void) override;	// 0F
		virtual void	Unk_10(void) override;	// 10
		virtual void	Unk_11(void) override;	// 11
		virtual void	Unk_12(void) override;	// 12
		virtual void	Unk_13(void) override;	// 13
		virtual void	Unk_14(void) override;	// 14
		virtual void	Unk_15(void) override;	// 15
		virtual void	Unk_16(void) override;	// 16
		virtual void	Unk_17(void) override;	// 17
		virtual void	Unk_18(void) override;	// 18


		// members
		UInt64	unk0C8;	// 0C8
		UInt64	unk0D0;	// 0D0
		UInt64	unk0D8;	// 0D8
		UInt64	unk0E0;	// 0E0
		UInt64	unk0E8;	// 0E8
		UInt64	unk0F0;	// 0F0
		UInt64	unk0F8;	// 0F8
		UInt64	unk100;	// 100
		UInt64	unk108;	// 108
		UInt64	unk110;	// 110
		UInt64	unk118;	// 118
		UInt64	unk120;	// 120
		UInt64	unk128;	// 128
		UInt64	unk130;	// 130
		UInt64	unk138;	// 138
		UInt64	unk140;	// 140
		UInt64	unk148;	// 148
		UInt64	unk150;	// 150
		UInt64	unk158;	// 158
		UInt64	unk160;	// 160
		UInt64	unk168;	// 168
		UInt64	unk170;	// 170
		UInt64	unk178;	// 178
		UInt64	unk180;	// 180
		UInt64	unk188;	// 188
		UInt64	unk190;	// 190
		UInt64	unk198;	// 198
		UInt64	unk1A0;	// 1A0
		UInt64	unk1A8;	// 1A8
		UInt64	unk1B0;	// 1B0
		UInt64	unk1B8;	// 1B8
		UInt64	unk1C0;	// 1C0
		UInt64	unk1C8;	// 1C8
		UInt64	unk1D0;	// 1D0
		UInt64	unk1D8;	// 1D8
		UInt64	unk1E0;	// 1E0
		UInt64	unk1E8;	// 1E8
		UInt64	unk1F0;	// 1F0
		UInt64	unk1F8;	// 1F8
		UInt64	unk200;	// 200
		UInt64	unk208;	// 208
		UInt64	unk210;	// 210
		UInt64	unk218;	// 218
	};
	STATIC_ASSERT(sizeof(BSXAudio2GameSound) == 0x220);
}
