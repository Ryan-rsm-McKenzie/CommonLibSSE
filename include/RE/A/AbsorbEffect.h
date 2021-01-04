#pragma once

#include "RE/V/ValueModifierEffect.h"

namespace RE
{
	class AbsorbEffect : public ValueModifierEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_AbsorbEffect;

		// override (ValueModifierEffect)
		virtual ~AbsorbEffect();  // 13

		virtual void Unk_1B(void) override;	 // 1B
		virtual void Unk_1D(void) override;	 // 1D
		virtual void Unk_1F(void) override;	 // 1F
	};
	static_assert(sizeof(AbsorbEffect) == 0x98);
}
