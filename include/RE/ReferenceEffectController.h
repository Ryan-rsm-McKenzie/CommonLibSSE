#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ReferenceEffectController


namespace RE
{
	class ReferenceEffectController
	{
	public:
		inline static const void* RTTI = RTTI_ReferenceEffectController;


		virtual ~ReferenceEffectController();	// 00

		// add
		virtual void	Unk_01(void);			// 01 - { return; }
		virtual void	Unk_02(void);			// 02 - { return 0.0; }
		virtual void	Unk_03(void);			// 03 - { return 1.0; }
		virtual void	Unk_04(void);			// 04 - { return; }
		virtual void	Unk_05(void);			// 05
		virtual void	Unk_06(void);			// 06 - { return 0; }
		virtual void	Unk_07(void);			// 07 - { return 0; }
		virtual void	Unk_08(void);			// 08 - { return 1; }
		virtual void	Unk_09(void);			// 09 - { return 0; }
		virtual void	Unk_0A(void);			// 0A - { return; }
		virtual void	Unk_0B(void) = 0;		// 0B
		virtual void	Unk_0C(void) = 0;		// 0C
		virtual void	Unk_0D(void) = 0;		// 0D
		virtual void	Unk_0E(void) = 0;		// 0E
		virtual void	Unk_0F(void);			// 0F
		virtual void	Unk_10(void);			// 10 - { return 0.0; }
		virtual void	Unk_11(void);			// 11 - { return 0; }
		virtual void	Unk_12(void);			// 12 - { return 1; }
		virtual void	Unk_13(void);			// 13 - { return 0; }
		virtual void	Unk_14(void);			// 14 - { return 0; }
		virtual void	Unk_15(void);			// 15
		virtual void	Unk_16(void);			// 16 - { return 0; }
		virtual void	Unk_17(void);			// 17 - { return 0; }
		virtual void	Unk_18(void);			// 18 - { return 0; }
		virtual void	Unk_19(void);			// 19 - { return 1; }
		virtual void	Unk_1A(void);			// 1A - { return 0; }
		virtual void	Unk_1B(void);			// 1B - { return 0; }
		virtual void	Unk_1C(void);			// 1C - { return 1; }
		virtual void	Unk_1D(void);			// 1D - { return 1; }
		virtual void	Unk_1E(void);			// 1E - { return; }
		virtual void	Unk_1F(void);			// 1F
		virtual void	Unk_20(void);			// 20 - { return 0; }
		virtual void	Unk_21(void);			// 21 - { return; }
		virtual void	Unk_22(void);			// 22 - { return; }
	};
	STATIC_ASSERT(sizeof(ReferenceEffectController) == 0x8);
}
