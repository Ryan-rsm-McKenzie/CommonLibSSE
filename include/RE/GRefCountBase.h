#pragma once

#include "RE/GRefCountImpl.h"  // GRefCountImpl
#include "RE/GRefCountBaseStatImpl.h"  // GRefCountBaseStatImpl
#include "RE/GStats.h"  // GStat
#include "RE/BSFixedString.h"


namespace RE
{
	template <class Ty, GStat Stat = GStat::kDefaultMem>
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
