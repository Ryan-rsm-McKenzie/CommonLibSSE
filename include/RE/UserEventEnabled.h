#pragma once

#include "RE/UserEvents.h"


namespace RE
{
	class UserEventEnabled
	{
	public:
		constexpr UserEventEnabled(UserEvents::Flag a_curFlags, UserEvents::Flag a_prevFlags) :
			curFlags(a_curFlags),
			prevFlags(a_prevFlags)
		{}


		// members
		UserEvents::Flag	curFlags;	// 0
		UserEvents::Flag	prevFlags;	// 4
	};
	STATIC_ASSERT(sizeof(UserEventEnabled) == 0x8);
}
