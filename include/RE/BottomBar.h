#pragma once

#include "RE/GFxValue.h"  // GFxValue


namespace RE
{
	struct BottomBar
	{
		GFxValue obj;	// 00 - kObject
	};
	STATIC_ASSERT(sizeof(BottomBar) == 0x18);
}
