#pragma once

#include "RE/B/BSTempEffect.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiAVObject;

	class BSTempEffectWeaponBlood : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffectWeaponBlood;
		inline static constexpr auto TYPE = TEMP_EFFECT_TYPE::kWeaponBlood;

		~BSTempEffectWeaponBlood() override;  // 00

		bool                           Update(float a_arg1) override;  // 28
		[[nodiscard]] TEMP_EFFECT_TYPE GetType() const override;       // 2C - { return 1; }

		static void ClearEffectForWeapon(NiAVObject* a_weapon3D);

		// members;
		NiPointer<NiAVObject> weapon3D;        // 030
		float                 alphaThreshold;  // 038
	};
	static_assert(sizeof(BSTempEffectWeaponBlood) == 0x40);
}
