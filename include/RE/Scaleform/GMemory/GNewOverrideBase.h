#pragma once

#include "RE/GMemory.h"


namespace RE
{
	template <UInt32 Stat>
	class GNewOverrideBase
	{
	public:
		enum
		{
			kStatType = Stat
		};


		GFC_MEMORY_REDEFINE_NEW(GNewOverrideBase, Stat);
	};
}
