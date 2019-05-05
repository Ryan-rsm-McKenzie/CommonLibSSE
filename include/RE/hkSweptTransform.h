#pragma once

#include "RE/hkQuaternion.h"  // hkQuaternion
#include "RE/hkVector4.h"  // hkVector4


namespace RE
{
	class hkSweptTransform
	{
	public:
		hkVector4		centerOfMass0;		// 00
		hkVector4		centerOfMass1;		// 10
		hkQuaternion	rotation0;			// 20
		hkQuaternion	rotation1;			// 30
		hkVector4		centerOfMassLocal;	// 40
	};
	STATIC_ASSERT(sizeof(hkSweptTransform) == 0x50);
}
