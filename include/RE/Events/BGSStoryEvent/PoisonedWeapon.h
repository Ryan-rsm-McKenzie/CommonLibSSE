#pragma once


namespace RE
{
	struct PoisonedWeapon
	{
	public:
		struct Event
		{
		public:
		};
		STATIC_ASSERT(sizeof(Event) == 0x1);
	};
}
