#pragma once

#include "RE/H/hkVector4.h"

namespace RE
{
	class hkAabb
	{
	public:
		// members
		hkVector4 min;  // 00
		hkVector4 max;  // 10
	};
	static_assert(sizeof(hkAabb) == 0x20);
}
