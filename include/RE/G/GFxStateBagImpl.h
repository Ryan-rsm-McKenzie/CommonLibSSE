#pragma once

#include "RE/G/GFxLogBase.h"
#include "RE/G/GFxStateBag.h"
#include "RE/G/GRefCountBase.h"

namespace RE
{
	class GFxStateBagImpl :
		public GRefCountBase<GFxStateBagImpl, GStatGroups::kGStat_Default_Mem>,  // 00
		public GFxStateBag,                                                      // 10
		public GFxLogBase<GFxStateBagImpl>                                       // 20
	{
	public:
		// members
		std::uint64_t unk28[7];
	};
#ifndef __INTELLISENSE__
	static_assert(sizeof(GFxStateBagImpl) == 0x60);
#endif
}
