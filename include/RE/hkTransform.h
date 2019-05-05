#pragma once

#include "RE/hkRotation.h"  // hkRotation
#include "RE/hkVector4.h"  // hkVector4


namespace RE
{
	class hkTransform
	{
	public:
		hkRotation	rotation;		// 00
		hkVector4	translation;	// 30
	};
	STATIC_ASSERT(sizeof(hkTransform) == 0x40);
}
