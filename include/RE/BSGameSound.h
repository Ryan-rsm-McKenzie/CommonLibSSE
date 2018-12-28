#pragma once

#include "RE/IXAudio2VoiceCallback.h"


namespace RE
{
	class BSGameSound : public IXAudio2VoiceCallback
	{
	public:
		// add
		virtual void	Unk_00();		// 00

		virtual ~BSGameSound();			// 01

		virtual void	Unk_02(void);	// 02
		virtual void	Unk_03(void);	// 03
		virtual void	Unk_04(void);	// 04 - pure
		virtual void	Unk_05(void);	// 05
		virtual void	Unk_06(void);	// 06 - pure
		virtual void	Unk_07(void);	// 07 - pure
		virtual void	Unk_08(void);	// 08 - pure
		virtual void	Unk_09(void);	// 09 - pure
		virtual void	Unk_0A(void);	// 0A - pure
		virtual void	Unk_0B(void);	// 0B
		virtual void	Unk_0C(void);	// 0C
		virtual void	Unk_0D(void);	// 0D - pure
		virtual void	Unk_0E(void);	// 0E
		virtual void	Unk_0F(void);	// 0F - pure
		virtual void	Unk_10(void);	// 10 - pure
		virtual void	Unk_11(void);	// 11 - pure
		virtual void	Unk_12(void);	// 12 - pure
		virtual void	Unk_13(void);	// 13
		virtual void	Unk_14(void);	// 14 - pure
		virtual void	Unk_15(void);	// 15 - pure
		virtual void	Unk_16(void);	// 16 - pure
		virtual void	Unk_17(void);	// 17 - pure
		virtual void	Unk_18(void);	// 18 - pure


		// members
		UInt64	unk08;	// 08
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
		UInt64	unk30;	// 30
		UInt64	unk38;	// 38
		UInt64	unk40;	// 40
		UInt64	unk48;	// 48
		UInt64	unk50;	// 50
		UInt64	unk58;	// 58
		UInt64	unk60;	// 60
		UInt64	unk68;	// 68
		UInt64	unk70;	// 70
		UInt64	unk78;	// 78
		UInt64	unk80;	// 80
		UInt64	unk88;	// 88
		UInt64	unk90;	// 90
		UInt64	unk98;	// 98
		UInt64	unkA0;	// A0
		UInt64	unkA8;	// A8
		UInt64	unkB0;	// B0
		UInt64	unkB8;	// B8
		UInt64	unkC0;	// C0
	};
	STATIC_ASSERT(sizeof(BSGameSound) == 0xC8);
}
