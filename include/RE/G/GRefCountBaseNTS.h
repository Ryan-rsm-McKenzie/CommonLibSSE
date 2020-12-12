#pragma once

#include "RE/Scaleform/GRefCount/GRefCountBaseStatImpl.h"
#include "RE/Scaleform/GRefCount/GRefCountNTSImpl.h"


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
