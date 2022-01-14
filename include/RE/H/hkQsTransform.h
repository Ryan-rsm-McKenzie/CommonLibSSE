#pragma once

#include "RE/H/hkQuaternion.h"
#include "RE/H/hkVector4.h"

namespace RE
{
	class hkQsTransform
	{
	public:
		// members
		hkVector4    translation;  // 00
		hkQuaternion rotation;     // 10
		hkVector4    scale;        // 20
	};
	static_assert(sizeof(hkQsTransform) == 0x30);
}
