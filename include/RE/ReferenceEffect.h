#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ReferenceEffect

#include "RE/BSTempEffect.h"  // BSTempEffect


namespace RE
{
	class ReferenceEffectController;


	class ReferenceEffect : public BSTempEffect
	{
	public:
		inline static const void* RTTI = RTTI_ReferenceEffect;


		virtual ~ReferenceEffect();												// 00

		// override (BSTempEffect)
		virtual const NiRTTI*	GetRTTI() const override;						// 02
		virtual void			Unk_27(void) override;							// 27
		virtual void			Unk_28(void) override;							// 28
		virtual void			Unk_2A(void) override;							// 2A
		virtual void			Unk_2B(void) override;							// 2B
		virtual void			Unk_2C(void) override;							// 2C - { return 8; }
		virtual void			Unk_2D(void) override;							// 2D
		virtual void			LoadEffect(BGSLoadGameBuffer* a_buf) override;	// 2E
		virtual void			Unk_2F(void) override;							// 2F

		// add
		virtual void			Unk_36(void);									// 36 - { return 0; }
		virtual void			Unk_37(void);									// 37 - { return; }
		virtual void			Unk_38(void);									// 38 - { return; }
		virtual void			Unk_39(void);									// 39
		virtual void			Unk_3A(void);									// 3A
		virtual void			Unk_3B(void);									// 3B - { return; }
		virtual void			Unk_3C(void);									// 3C
		virtual void			Unk_3D(void);									// 3D - { return 1; }
		virtual void			Unk_3E(void);									// 3E - { return; }


		// members
		ReferenceEffectController*	controller;	// 30
		RefHandle					unk38;		// 38
		RefHandle					unk3C;		// 3C
		UInt8						unk40;		// 40
		UInt8						unk41;		// 41
		UInt16						unk42;		// 42
		UInt32						unk44;		// 44
	};
	STATIC_ASSERT(sizeof(ReferenceEffect) == 0x48);
}
