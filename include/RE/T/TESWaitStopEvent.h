#pragma once

namespace RE
{
	struct TESWaitStopEvent
	{
	public:
		// members
		bool interrupted;  // 0
	};
	static_assert(sizeof(TESWaitStopEvent) == 0x1);
}
