#pragma once

#include "RE/hkVector4.h"  // hkVector4


namespace RE
{
	class hkContactPoint
	{
	public:
		hkVector4	position;			// 00
		hkVector4	separatingNormal;	// 10
	};
	STATIC_ASSERT(sizeof(hkContactPoint) == 0x20);
}
