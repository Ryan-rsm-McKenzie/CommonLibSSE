#pragma once

#include "RE/BSHavok/hkMatrix3/hkRotation.h"
#include "RE/BSHavok/hkVector4.h"


namespace RE
{
	class hkTransform
	{
	public:
		hkRotation rotation;	 // 00
		hkVector4  translation;	 // 30
	};
	static_assert(sizeof(hkTransform) == 0x40);
}
