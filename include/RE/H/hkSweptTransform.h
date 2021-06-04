#pragma once

#include "RE/H/hkQuaternion.h"
#include "RE/H/hkVector4.h"

namespace RE
{
	class hkSweptTransform
	{
	public:
		hkVector4    centerOfMass0;      // 00
		hkVector4    centerOfMass1;      // 10
		hkQuaternion rotation0;          // 20
		hkQuaternion rotation1;          // 30
		hkVector4    centerOfMassLocal;  // 40
	};
	static_assert(sizeof(hkSweptTransform) == 0x50);
}
