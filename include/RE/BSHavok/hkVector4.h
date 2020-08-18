#pragma once

#include "hkSseMathTypes.h"


namespace RE
{
	class hkVector4
	{
	public:
		hkQuadReal quad{};	// 00
	};
	static_assert(sizeof(hkVector4) == 0x10);
}
