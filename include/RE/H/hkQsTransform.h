#pragma once

#include "hkQuaternion.h"
#include "hkVector4.h"

namespace RE
{
	class hkQsTransform
	{
	public:
		hkVector4    translation;
		hkQuaternion rotation;
		hkVector4    scale;
	};
	static_assert(sizeof(hkQsTransform) == 0x30);
}
