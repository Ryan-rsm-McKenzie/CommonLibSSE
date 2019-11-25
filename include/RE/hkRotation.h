#pragma once

#include "RE/hkMatrix3.h"


namespace RE
{
	class alignas(0x10) hkRotation : public hkMatrix3
	{
	public:
	};
	STATIC_ASSERT(sizeof(hkRotation) == 0x30);
}
