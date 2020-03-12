#pragma once

#include "RE/NiPoint3.h"


namespace RE
{
	class NiBound
	{
	public:
		// members
		NiPoint3 center;  // 00
		float	 radius;  // 0C
	};
	STATIC_ASSERT(sizeof(NiBound) == 0x10);
}
