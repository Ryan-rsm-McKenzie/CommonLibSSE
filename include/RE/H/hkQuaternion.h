#pragma once

#include "RE/BSHavok/hkVector4.h"


namespace RE
{
	class hkQuaternion
	{
	public:
		hkVector4 vec;	// 00
	};
	static_assert(sizeof(hkQuaternion) == 0x10);
}
