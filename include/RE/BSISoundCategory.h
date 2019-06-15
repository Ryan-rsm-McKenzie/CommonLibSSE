#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSISoundCategory


namespace RE
{
	class BSISoundCategory
	{
	public:
		inline static const void* RTTI = RTTI_BSISoundCategory;


		virtual ~BSISoundCategory();		// 00

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
	};
	STATIC_ASSERT(sizeof(BSISoundCategory) == 0x8);
}
