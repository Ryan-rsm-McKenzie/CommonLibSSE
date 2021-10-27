#pragma once

#include "RE/G/GAtomic.h"
#include "RE/G/GFxLogBase.h"
#include "RE/G/GFxStateBag.h"
#include "RE/G/GRefCountBase.h"

namespace RE
{
	class GFxStateBagImpl;

	class GFxLoaderImpl :
		public GRefCountBase<GFxLoaderImpl, GStatGroups::kGStat_Default_Mem>,  // 00
		public GFxStateBag,                                                    // 10
		public GFxLogBase<GFxLoaderImpl>                                       // 20
	{
	public:
		~GFxLoaderImpl() override;  // 00

		// members
		GFxStateBagImpl* stateBagImpl;  // 28
		std::uint64_t    pad30;         // 30
		void*            pad38;         // 38
		void*            pad40;         // 40
		GLock            lock;          // 48
		std::uint8_t     pad70;         // 70
		std::uint8_t     pad71;         // 71
		std::uint16_t    pad72;         // 72
		std::uint32_t    pad74;         // 74
	};
#ifndef __INTELLISENSE__
	static_assert(sizeof(GFxLoaderImpl) == 0x78);
#endif
}
