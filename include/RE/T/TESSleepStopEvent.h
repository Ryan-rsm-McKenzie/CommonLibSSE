#pragma once

namespace RE
{
	struct TESSleepStopEvent
	{
	public:
		// members
		bool interrupted;  // 0
	};
	static_assert(sizeof(TESSleepStopEvent) == 0x1);
}
