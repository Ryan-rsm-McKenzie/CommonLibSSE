#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MoviePlayer


namespace RE
{
	class MoviePlayer
	{
		inline static const void* RTTI = RTTI_MoviePlayer;


		virtual ~MoviePlayer();				// 00

		// add
		virtual void	Unk_01(void) = 0;	// 01
		virtual void	Unk_02(void) = 0;	// 02
		virtual void	Unk_03(void) = 0;	// 03
		virtual void	Unk_04(void) = 0;	// 04
		virtual void	Unk_05(void) = 0;	// 05
		virtual void	Unk_06(void) = 0;	// 06
		virtual void	Unk_07(void) = 0;	// 07
		virtual void	Unk_08(void) = 0;	// 08
		virtual void	Unk_09(void) = 0;	// 09
		virtual void	Unk_0A(void) = 0;	// 0A
		virtual void	Unk_0B(void) = 0;	// 0B
		virtual void	Unk_0C(void) = 0;	// 0C
		virtual void	Unk_0D(void);		// 0D


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
	};
	STATIC_ASSERT(sizeof(MoviePlayer) == 0x58);
}
