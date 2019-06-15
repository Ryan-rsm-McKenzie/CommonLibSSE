#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSGameSound


namespace RE
{
	class BSGameSound
	{
	public:
		inline static const void* RTTI = RTTI_BSGameSound;


		// add
		virtual void	Unk_00(void);		// 00 - { return; }

		virtual ~BSGameSound();				// 01

		virtual void	Unk_02(void);		// 02 - { return (unk5C >> 4) & 1; }
		virtual void	Unk_03(void);		// 03
		virtual void	Unk_04(void) = 0;	// 04
		virtual void	Unk_05(void);		// 05
		virtual void	Unk_06(void) = 0;	// 06
		virtual void	Unk_07(void) = 0;	// 07
		virtual void	Unk_08(void) = 0;	// 08
		virtual void	Unk_09(void) = 0;	// 09
		virtual void	Unk_0A(void) = 0;	// 0A
		virtual void	Unk_0B(void);		// 0B - { unk5C |= 0x800; }
		virtual void	Unk_0C(void);		// 0C
		virtual void	Unk_0D(void) = 0;	// 0D
		virtual void	Unk_0E(void);		// 0E
		virtual void	Unk_0F(void) = 0;	// 0F
		virtual void	Unk_10(void) = 0;	// 10
		virtual void	Unk_11(void) = 0;	// 11
		virtual void	Unk_12(void) = 0;	// 12
		virtual void	Unk_13(void);		// 13 - { return; }
		virtual void	Unk_14(void) = 0;	// 14
		virtual void	Unk_15(void) = 0;	// 15
		virtual void	Unk_16(void) = 0;	// 16
		virtual void	Unk_17(void) = 0;	// 17
		virtual void	Unk_18(void) = 0;	// 18


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
