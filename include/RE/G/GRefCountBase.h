#pragma once

#include "RE/G/GMemory.h"
#include "RE/G/GRefCountBaseStatImpl.h"
#include "RE/G/GRefCountImpl.h"

namespace RE
{
	// Overrides new/delete operators to use MemoryHeap
	template <class T, std::uint32_t STAT>
	class GRefCountBase : public GRefCountBaseStatImpl<GRefCountImpl, STAT>
	{
	public:
		enum
		{
			kStatType = STAT
		};
	};
}
