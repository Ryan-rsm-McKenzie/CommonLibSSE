#pragma once


namespace RE
{
	struct TESWaitStopEvent
	{
		// members
		bool interrupted;	// 0
	};
	STATIC_ASSERT(sizeof(TESWaitStopEvent) == 0x1);
}
