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
		static_assert(sizeof(Event) == 0x1);
	};
}
