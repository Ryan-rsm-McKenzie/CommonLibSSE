#pragma once

#include "RE/G/GFxTask.h"

namespace RE
{
	class GFxLoadStates;

	class GFxLoaderTask : public GFxTask
	{
	public:
		// members
		GFxLoadStates* loadStates;  // 18
	};
	static_assert(sizeof(GFxLoaderTask) == 0x20);
}
