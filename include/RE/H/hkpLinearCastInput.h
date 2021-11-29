#pragma once

#include "RE/H/hkVector4.h"

namespace RE
{
	struct hkpLinearCastInput
	{
	public:
		// members
		hkVector4     to;                   // 00
		float         maxExtraPenetration;  // 10
		float         startPointTolerance;  // 14
		std::uint64_t pad18;                // 18
	};
	static_assert(sizeof(hkpLinearCastInput) == 0x20);
}
