#pragma once

#include "RE/U/UserEvents.h"

namespace RE
{
	class UserEventEnabled
	{
	public:
		using UEFlag = UserEvents::USER_EVENT_FLAG;

		// members
		stl::enumeration<UEFlag, std::uint32_t> newUserEventFlag;  // 0
		stl::enumeration<UEFlag, std::uint32_t> oldUserEventFlag;  // 4
	};
	static_assert(sizeof(UserEventEnabled) == 0x8);
}
