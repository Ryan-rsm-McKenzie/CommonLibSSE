#pragma once

namespace RE
{
	namespace BSScript
	{
		struct StatsEvent
		{
		public:
			// members
			std::uint32_t runningStacksCount;    // 00
			std::uint32_t suspendedStacksCount;  // 04
			std::uint32_t functionMsgCount;      // 08
			std::uint32_t detachedObjectCount;   // 0C
		};
		static_assert(sizeof(StatsEvent) == 0x10);
	}
}
