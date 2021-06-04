#pragma once

#include "RE/H/hkVector4.h"

namespace RE
{
	struct hkpWorldRayCastInput
	{
	public:
		// members
		hkVector4     from;                                  // 00
		hkVector4     to;                                    // 10
		bool          enableShapeCollectionFilter{ false };  // 20
		std::uint32_t filterInfo{ 0 };                       // 24
	};
	static_assert(sizeof(hkpWorldRayCastInput) == 0x30);
}
