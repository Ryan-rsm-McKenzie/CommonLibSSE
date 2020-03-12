#pragma once

#include "RE/hkRefVariant.h"
#include "RE/hkbEventBase.h"


namespace RE
{
	class hkbEvent : public hkbEventBase
	{
	public:
		// members
		hkRefVariant sender;  // 10
	};
	STATIC_ASSERT(sizeof(hkbEvent) == 0x18);
}
