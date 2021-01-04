#pragma once

#include "RE/B/BSTempEffect.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiAVObject;

	class BSTempEffectDebris : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffectDebris;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTempEffectDebris;

		virtual ~BSTempEffectDebris();	// 00

		virtual const NiRTTI*	 GetRTTI() const override;		 // 02
		virtual bool			 Update(float a_arg1) override;	 // 28
		virtual NiAVObject*		 Get3D() const override;		 // 29
		virtual TEMP_EFFECT_TYPE GetType() const;				 // 2C - { return kDebris; }

		// members;
		NiPointer<NiAVObject> debris3D;		   // 030
		const char*			  debrisFileName;  // 038
		bool				  unk40;		   // 040
		std::uint8_t		  unk41;		   // 041
		std::uint8_t		  pad42;		   // 042
		std::uint8_t		  pad43;		   // 043
		std::uint32_t		  pad44;		   // 044
	};
	static_assert(sizeof(BSTempEffectDebris) == 0x48);
}
