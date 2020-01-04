#pragma once


namespace RE
{
	struct PoisonedWeapon
	{
		struct Event
		{};
		STATIC_ASSERT(sizeof(Event) == 0x1);
	};
}
