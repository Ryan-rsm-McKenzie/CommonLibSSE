#pragma once


namespace RE
{
	struct TESWaitStopEvent
	{
		UInt8 pad0;	// 0
	};
	STATIC_ASSERT(sizeof(TESWaitStopEvent) == 0x1);
}
