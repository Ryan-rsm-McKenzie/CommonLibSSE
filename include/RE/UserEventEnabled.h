#pragma once

#include "RE/UserEvents.h"


namespace RE
{
	class UserEventEnabled
	{
	public:
		using UEFlag = UserEvents::USER_EVENT_FLAG;


		constexpr UserEventEnabled(UEFlag a_curFlags, UEFlag a_prevFlags) :
			curFlags(a_curFlags),
			prevFlags(a_prevFlags)
		{}


		// members
		UEFlag	curFlags;	// 0
		UEFlag	prevFlags;	// 4
	};
	STATIC_ASSERT(sizeof(UserEventEnabled) == 0x8);
}
