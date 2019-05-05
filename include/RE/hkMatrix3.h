#pragma once

#include "RE/hkVector4.h"  // hkVector4


namespace RE
{
	class hkMatrix3
	{
	public:
		hkVector4	col0;	// 00
		hkVector4	col1;	// 10
		hkVector4	col2;	// 20
	};
	STATIC_ASSERT(sizeof(hkMatrix3) == 0x30);
}
