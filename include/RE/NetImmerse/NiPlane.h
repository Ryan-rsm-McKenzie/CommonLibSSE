#pragma once

#include "RE/NetImmerse/NiPoint3.h"


namespace RE
{
	class NiPlane
	{
	public:
		// members
		NiPoint3 normal;	// 00
		float	 constant;	// 0C
	};
	STATIC_ASSERT(sizeof(NiPlane) == 0x10);
}
