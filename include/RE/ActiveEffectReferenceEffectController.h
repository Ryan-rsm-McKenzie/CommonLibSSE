#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ActiveEffectReferenceEffectController

#include "RE/ReferenceEffectController.h"  // ReferenceEffectController


namespace RE
{
	class ActiveEffect;


	class ActiveEffectReferenceEffectController : public ReferenceEffectController
	{
	public:
		inline static const void* RTTI = RTTI_ActiveEffectReferenceEffectController;


		virtual ~ActiveEffectReferenceEffectController();	// 00

		// override (ReferenceEffectController)
		virtual void	Unk_01(void) override;				// 01
		virtual void	Unk_02(void) override;				// 02
		virtual void	Unk_03(void) override;				// 03
		virtual void	Unk_04(void) override;				// 04
		virtual void	Unk_05(void) override;				// 05
		virtual void	Unk_06(void) override;				// 06
		virtual void	Unk_07(void) override;				// 07
		virtual void	Unk_08(void) override;				// 08
		virtual void	Unk_09(void) override;				// 09
		virtual void	Unk_0A(void) override;				// 0A
		virtual void	Unk_0B(void) override;				// 0B
		virtual void	Unk_0C(void) override;				// 0C
		virtual void	Unk_0D(void) override;				// 0D
		virtual void	Unk_0E(void) override;				// 0E - { return 0; }
		virtual void	Unk_17(void) override;				// 17
		virtual void	Unk_18(void) override;				// 18
		virtual void	Unk_1E(void) override;				// 1E
		virtual void	Unk_1F(void) override;				// 1F - { return unk14; }
		virtual void	Unk_20(void) override;				// 20
		virtual void	Unk_21(void) override;				// 21
		virtual void	Unk_22(void) override;				// 22


		// members
		ActiveEffect*	effect;	// 08
		UInt32			unk10;	// 10
		UInt32			unk14;	// 14
		UInt64			unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ActiveEffectReferenceEffectController) == 0x20);
}
