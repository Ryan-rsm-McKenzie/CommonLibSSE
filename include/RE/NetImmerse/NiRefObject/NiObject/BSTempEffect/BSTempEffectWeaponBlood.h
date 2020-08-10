#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/BSTempEffect.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class NiAVObject;


	class BSTempEffectWeaponBlood : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffectWeaponBlood;


		virtual ~BSTempEffectWeaponBlood();	 // 00

		virtual bool			 Update(float a_arg1) override;	 // 28
		virtual TEMP_EFFECT_TYPE GetType() const override;		 // 2C - { return 1; }


		// members;
		NiPointer<NiAVObject> weapon3D;	   // 030
		float				  alphaThreshold;  // 038
	};
	static_assert(sizeof(BSTempEffectWeaponBlood) == 0x40);
}
