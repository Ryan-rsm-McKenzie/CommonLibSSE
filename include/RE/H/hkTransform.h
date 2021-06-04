#pragma once

#include "RE/H/hkRotation.h"
#include "RE/H/hkVector4.h"

namespace RE
{
	class hkTransform
	{
	public:
		hkRotation rotation;     // 00
		hkVector4  translation;  // 30
	};
	static_assert(sizeof(hkTransform) == 0x40);
}
