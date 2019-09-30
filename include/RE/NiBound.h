#pragma once

#include "RE/NiPoint3.h"  // NiPoint3


namespace RE
{
	class NiBound
	{
	public:
		// members
		NiPoint3	center;	// 00
		float		radius;	// 0C
	};
	STATIC_ASSERT(sizeof(NiBound) == 0x10);
}
