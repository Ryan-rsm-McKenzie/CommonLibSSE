#pragma once

#include "RE/GFxValue.h"


namespace RE
{
	struct BottomBar
	{
		GFxValue obj;  // 00 - kObject
	};
	STATIC_ASSERT(sizeof(BottomBar) == 0x18);
}
