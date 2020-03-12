#pragma once

#include "RE/hkVector4.h"


namespace RE
{
	class hkAabb
	{
	public:
		// members
		hkVector4 min;	// 00
		hkVector4 max;	// 10
	};
	STATIC_ASSERT(sizeof(hkAabb) == 0x20);
}
