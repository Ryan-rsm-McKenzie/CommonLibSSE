#pragma once

#include "RE/BSHavok/hkBaseTypes.h"
#include "RE/BSHavok/hkSweptTransform.h"
#include "RE/BSHavok/hkTransform.h"
#include "RE/BSHavok/hkVector4.h"


namespace RE
{
	class hkMotionState
	{
	public:
		// members
		hkTransform		 transform;			  // 00
		hkSweptTransform sweptTransform;	  // 40
		hkVector4		 deltaAngle;		  // 90
		float			 objectRadius;		  // A0
		hkHalf			 linearDamping;		  // A4
		hkHalf			 angularDamping;	  // A6
		hkHalf			 timeFactor;		  // A8
		hkUFloat8		 maxLinearVelocity;	  // AA
		hkUFloat8		 maxAngularVelocity;  // AB
		std::uint8_t	 deactivationClass;	  // AC
		std::uint8_t	 padAD;				  // AD
		std::uint16_t	 padAE;				  // AE
	};
	static_assert(sizeof(hkMotionState) == 0xB0);
}
