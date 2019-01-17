#pragma once

#include "RE/GRefCountImpl.h"  // GRefCountImpl
#include "RE/GRefCountBaseStatImpl.h"  // GRefCountBaseStatImpl
#include "RE/GStats.h"  // GStat
#include "RE/BSFixedString.h"


namespace RE
{
	// Overrides new/delete operators to use MemoryHeap
	template <class C, GStat Stat = GStat::kDefaultMem>
	class GRefCountBase : public GRefCountBaseStatImpl<GRefCountImpl, Stat>
	{
	public:
		enum { kStatType = Stat };

		virtual ~GRefCountBase()	// 00
		{}

		constexpr GRefCountBase() :
			GRefCountBaseStatImpl<GRefCountImpl, Stat>()
		{}
	};
}
