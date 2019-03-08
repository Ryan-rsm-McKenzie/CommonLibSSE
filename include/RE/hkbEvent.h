#pragma once

#include "RE/hkbEventBase.h"  // hkbEventBase
#include "RE/hkRefVariant.h"  // hkRefVariant


namespace RE
{
	class hkbEvent : public hkbEventBase
	{
	public:
		// members
		hkRefVariant sender;	// 10
	};
	STATIC_ASSERT(sizeof(hkbEvent) == 0x18);
}
