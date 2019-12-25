#pragma once


namespace RE
{
	struct PoisonedWeapon
	{
		struct Event
		{
			// members
			UInt8 pad0;	// 0
		};
		STATIC_ASSERT(sizeof(Event) == 0x1);
	};
}
