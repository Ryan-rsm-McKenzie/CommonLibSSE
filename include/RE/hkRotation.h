#pragma once

#include "RE/hkMatrix3.h"  // hkMatrix3


namespace RE
{
	class alignas(16) hkRotation : public hkMatrix3
	{
	public:
	};
	STATIC_ASSERT(sizeof(hkRotation) == 0x30);
}
