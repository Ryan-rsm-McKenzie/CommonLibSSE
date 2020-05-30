#pragma once

#include "RE/BSPointerHandle.h"


namespace RE
{
	struct REF_ACTIVATE_DATA
	{
	public:
		// members
		ObjectRefHandle activateRef;	// 00
		float			activateDelay;	// 04
	};
	STATIC_ASSERT(sizeof(REF_ACTIVATE_DATA) == 0x8);
}
