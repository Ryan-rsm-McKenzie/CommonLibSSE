#pragma once


namespace RE
{
	namespace BSScript
	{
		struct StatsEvent
		{
		public:
			// members
			UInt32 runningStacksCount;	  // 00
			UInt32 suspendedStacksCount;  // 04
			UInt32 functionMsgCount;	  // 08
			UInt32 detachedObjectCount;	  // 0C
		};
		STATIC_ASSERT(sizeof(StatsEvent) == 0x10);
	}
}
