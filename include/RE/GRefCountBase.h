#pragma once

#include "RE/GRefCountImpl.h"  // GRefCountImpl
#include "RE/GRefCountBaseStatImpl.h"  // GRefCountBaseStatImpl
#include "RE/BSFixedString.h"


namespace RE
{
	// Overrides new/delete operators to use MemoryHeap
	template <class C, UInt32 Stat>
	class GRefCountBase : public GRefCountBaseStatImpl<GRefCountImpl, Stat>
	{
	public:
		enum { kStatType = Stat };


		constexpr GRefCountBase() :
			GRefCountBaseStatImpl<GRefCountImpl, Stat>()
		{}


		virtual ~GRefCountBase()	// 00
		{}
	};
}
