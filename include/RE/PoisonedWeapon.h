#pragma once


namespace RE
{
	struct PoisonedWeapon
	{
	public:
		struct Event
		{
		public:
			UInt32 refHandle;	// 0 - always invalid
		};
		STATIC_ASSERT(sizeof(Event) == 0x4);
	};
}
