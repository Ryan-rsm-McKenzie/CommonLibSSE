#pragma once

#include "RE/NiPoint3.h"  // NiPoint3


namespace RE
{
	class NiPlane
	{
	public:
		NiPoint3	normal;		// 00
		float		constant;	// 0C
	};
	STATIC_ASSERT(sizeof(NiPlane) == 0x10);
}
