#pragma once

#include "RE/hkVector4.h"


namespace RE
{
	struct hkpLinearCastInput
	{
	public:
		// members
		hkVector4 to;					// 00
		float	  maxExtraPenetration;	// 10
		float	  startPointTolerance;	// 14
		UInt64	  pad18;				// 18
	};
	STATIC_ASSERT(sizeof(hkpLinearCastInput) == 0x20);
}
