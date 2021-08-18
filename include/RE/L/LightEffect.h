#pragma once

#include "RE/A/ActiveEffect.h"

namespace RE
{
	class NiPointLight;

	class LightEffect : public ActiveEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_LightEffect;
		inline static constexpr auto VTABLE = VTABLE_LightEffect;

		// override (ActiveEffect)
		virtual void Unk_04(void) override;  // 04
		virtual void Unk_10(void) override;  // 0A
		virtual void Unk_11(void) override;  // 0B

		virtual ~LightEffect();  // 13

		virtual void Unk_14() override;  // 14
		virtual void Unk_15() override;  // 15

		// members
		NiPointer<NiPointLight> light;  // 90
	};
	static_assert(sizeof(LightEffect) == 0x98);
}
