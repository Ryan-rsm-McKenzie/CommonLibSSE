#pragma once

#include "RE/H/hkBaseTypes.h"

namespace RE
{
	class hkStepInfo
	{
	public:
		alignas(0x10) hkTime startTime;  // 00
		hkTime endTime;                  // 04
		float  deltaTime;                // 08
		float  invDeltaTime;             // 0C
	};
	static_assert(sizeof(hkStepInfo) == 0x10);
}
