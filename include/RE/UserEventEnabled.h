#pragma once

#include "RE/UserEvents.h"


namespace RE
{
	class UserEventEnabled
	{
	public:
		using UEFlag = UserEvents::USER_EVENT_FLAG;


		constexpr UserEventEnabled(UEFlag a_new, UEFlag a_old) :
			newUserEventFlag(a_new),
			oldUserEventFlag(a_old)
		{}


		// members
		UEFlag newUserEventFlag;  // 0
		UEFlag oldUserEventFlag;  // 4
	};
	STATIC_ASSERT(sizeof(UserEventEnabled) == 0x8);
}
