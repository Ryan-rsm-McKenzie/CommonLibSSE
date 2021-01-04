#pragma once

#include "RE/H/hkRefVariant.h"
#include "RE/H/hkbEventBase.h"

namespace RE
{
	class hkbEvent : public hkbEventBase
	{
	public:
		// members
		hkRefVariant sender;  // 10
	};
	static_assert(sizeof(hkbEvent) == 0x18);
}
