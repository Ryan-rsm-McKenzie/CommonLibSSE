#pragma once


namespace RE
{
	struct PoisonedWeapon
	{
	public:
		struct Event
		{
		public:
			UInt32 pad0;	// 0
		};
		STATIC_ASSERT(sizeof(Event) == 0x4);
	};
}
