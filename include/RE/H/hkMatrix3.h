#pragma once

#include "RE/H/hkVector4.h"

namespace RE
{
	class hkMatrix3
	{
	public:
		hkVector4 col0;  // 00
		hkVector4 col1;  // 10
		hkVector4 col2;  // 20
	};
	static_assert(sizeof(hkMatrix3) == 0x30);
}
