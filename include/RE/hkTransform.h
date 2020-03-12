#pragma once

#include "RE/hkRotation.h"
#include "RE/hkVector4.h"


namespace RE
{
	class hkTransform
	{
	public:
		hkRotation rotation;	 // 00
		hkVector4  translation;	 // 30
	};
	STATIC_ASSERT(sizeof(hkTransform) == 0x40);
}
