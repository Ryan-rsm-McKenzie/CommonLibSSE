#pragma once

#include "hkVector4.h"
#include "hkQuaternion.h"

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
