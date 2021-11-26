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
		void Unk_04(void) override;  // 04
		void Unk_10(void) override;  // 0A
		void Unk_11(void) override;  // 0B

		~LightEffect() override;  // 13

		void Start() override;   // 14
		void Finish() override;  // 15

		// members
		NiPointer<NiPointLight> light;  // 90
	};
	static_assert(sizeof(LightEffect) == 0x98);
}
