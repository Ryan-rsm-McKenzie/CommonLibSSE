#pragma once

#include "RE/G/GFxValue.h"

namespace RE
{
	struct BottomBar
	{
	public:
		// members
		GFxValue obj;  // 00 - kObject
	};
	static_assert(sizeof(BottomBar) == 0x18);
}
