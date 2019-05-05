#pragma once

#include "RE/hkVector4.h"  // hkVector4


namespace RE
{
	class hkQuaternion
	{
	public:
		hkVector4 vec;	// 00
	};
	STATIC_ASSERT(sizeof(hkQuaternion) == 0x10);
}
