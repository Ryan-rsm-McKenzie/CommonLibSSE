#pragma once

#include "RE/BSHavok/hkRefPtr/hkRefVariant.h"
#include "RE/BSHavok/hkbEventBase/hkbEventBase.h"


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
