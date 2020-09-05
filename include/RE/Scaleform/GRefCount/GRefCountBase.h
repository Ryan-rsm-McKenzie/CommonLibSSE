#pragma once

#include "RE/Scaleform/GMemory/GMemory.h"
#include "RE/Scaleform/GRefCount/GRefCountBaseStatImpl.h"
#include "RE/Scaleform/GRefCount/GRefCountImpl.h"


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
