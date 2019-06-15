#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SummonCreatureEffect

#include "RE/ActiveEffect.h"  // ActiveEffect


namespace RE
{
	class SummonCreatureEffect : public ActiveEffect
	{
	public:
		inline static const void* RTTI = RTTI_SummonCreatureEffect;


		// override (ActiveEffect)
		virtual void	Unk_04(void) override;	// 04
		virtual void	Unk_07(void) override;	// 07
		virtual void	Unk_08(void) override;	// 08
		virtual void	Unk_09(void) override;	// 09
		virtual void	Unk_0A(void) override;	// 0A
		virtual void	Unk_0D(void) override;	// 0D
		virtual void	Unk_12(void) override;	// 12

		virtual ~SummonCreatureEffect();		// 13

		virtual void	Unk_14(void) override;	// 14
		virtual void	Unk_15(void) override;	// 15


		// members
		UInt64	unk90;	// 90
		UInt64	unk98;	// 98
		UInt64	unkA0;	// A0
		UInt64	unkA8;	// A8
		UInt64	unkB0;	// B0
		UInt64	unkB8;	// B8
	};
	STATIC_ASSERT(sizeof(SummonCreatureEffect) == 0xC0);
}
