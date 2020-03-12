#pragma once

#include "RE/GMemory.h"
#include "RE/GRefCountBaseStatImpl.h"
#include "RE/GRefCountImpl.h"


namespace RE
{
	// Overrides new/delete operators to use MemoryHeap
	template <class T, UInt32 STAT>
	class GRefCountBase : public GRefCountBaseStatImpl<GRefCountImpl, STAT>
	{
	public:
		enum
		{
			kStatType = STAT
		};


		GRefCountBase() = default;
	};
}
