#pragma once

#include "RE/G/GRefCountBaseStatImpl.h"
#include "RE/G/GRefCountNTSImpl.h"

namespace RE
{
	template <class C, std::uint32_t Stat>
	class GRefCountBaseNTS : public GRefCountBaseStatImpl<GRefCountNTSImpl, Stat>
	{
	public:
		enum
		{
			kStatType = Stat
		};

		GRefCountBaseNTS() = default;
	};
}
