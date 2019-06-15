#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ValueModifierEffect

#include "RE/ActiveEffect.h"  // ActiveEffect
#include "RE/ActorValues.h"  // ActorValue


namespace RE
{
	class ValueModifierEffect : public ActiveEffect
	{
	public:
		inline static const void* RTTI = RTTI_ValueModifierEffect;


		// override (ActiveEffect)
		virtual void	Unk_01(void) override;	// 01
		virtual void	Unk_04(void) override;	// 04
		virtual void	Unk_06(void) override;	// 06
		virtual void	Unk_11(void) override;	// 11 - { return  1; };
		virtual void	Unk_12(void) override;	// 12

		virtual ~ValueModifierEffect();			// 13

		virtual void	Unk_14(void) override;	// 14
		virtual void	Unk_15(void) override;	// 15
		virtual void	Unk_17(void) override;	// 17
		virtual void	Unk_18(void) override;	// 18

		// add
		virtual void	Unk_19(void);			// 19
		virtual void	Unk_1A(void);			// 1A
		virtual void	Unk_1B(void);			// 1B
		virtual void	Unk_1C(void);			// 1C
		virtual void	Unk_1D(void);			// 1D
		virtual void	Unk_1E(void);			// 1E
		virtual void	Unk_1F(void);			// 1F
		virtual void	Unk_20(void);			// 20


		// members
		ActorValue	actorValue;	// 90
		UInt32		pad94;		// 94
	};
	STATIC_ASSERT(sizeof(ValueModifierEffect) == 0x98);
}
