#pragma once

#include "RE/GRefCountImpl.h"  // GRefCountImpl
#include "RE/GRefCountBaseStatImpl.h"  // GRefCountBaseStatImpl


namespace RE
{
	// Overrides new/delete operators to use MemoryHeap
	template <class T, UInt32 STAT>
	class GRefCountBase : public GRefCountBaseStatImpl<GRefCountImpl, STAT>
	{
	public:
		enum { kStatType = STAT };


		GRefCountBase() = default;
	};
}
