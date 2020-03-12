#pragma once

#include "RE/hkBaseTypes.h"
#include "RE/hkSweptTransform.h"
#include "RE/hkTransform.h"
#include "RE/hkVector4.h"


namespace RE
{
	class hkMotionState
	{
	public:
		hkTransform		 transform;			  // 00
		hkSweptTransform sweptTransform;	  // 40
		hkVector4		 deltaAngle;		  // 90
		float			 objectRadius;		  // A0
		hkHalf			 linearDamping;		  // A4
		hkHalf			 angularDamping;	  // A6
		hkHalf			 timeFactor;		  // A8
		hkUFloat8		 maxLinearVelocity;	  // AA
		hkUFloat8		 maxAngularVelocity;  // AB
		UInt8			 deactivationClass;	  // AC
		UInt8			 padAD;				  // AD
		UInt16			 padAE;				  // AE
	};
	STATIC_ASSERT(sizeof(hkMotionState) == 0xB0);
}
