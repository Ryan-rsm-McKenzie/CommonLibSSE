#pragma once

#include "RE/GFxValue.h"


namespace RE
{
	struct BottomBar
	{
	public:
		// members
		GFxValue obj;  // 00 - kObject
	};
	STATIC_ASSERT(sizeof(BottomBar) == 0x18);
}
