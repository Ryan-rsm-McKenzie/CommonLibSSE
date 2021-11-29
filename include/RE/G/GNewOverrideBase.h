#pragma once

#include "RE/G/GMemory.h"

namespace RE
{
	template <std::uint32_t Stat>
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
