#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IVMSaveLoadInterface


namespace RE
{
	namespace BSScript
	{
		class IVMSaveLoadInterface
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IVMSaveLoadInterface;


			virtual ~IVMSaveLoadInterface();	// 00

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
			virtual void	Unk_0D(void) = 0;	// 0D
			virtual void	Unk_0E(void) = 0;	// 0E
			virtual void	Unk_0F(void) = 0;	// 0F
			virtual void	Unk_10(void) = 0;	// 10
			virtual void	Unk_11(void) = 0;	// 11
			virtual void	Unk_12(void) = 0;	// 12
			virtual void	Unk_13(void) = 0;	// 13
			virtual void	Unk_14(void) = 0;	// 14
			virtual void	Unk_15(void) = 0;	// 15
			virtual void	Unk_16(void) = 0;	// 16
		};
		STATIC_ASSERT(sizeof(IVMSaveLoadInterface) == 0x8);
	}
}
