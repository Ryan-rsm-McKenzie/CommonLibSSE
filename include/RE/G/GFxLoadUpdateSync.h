#pragma once

#include "RE/G/GMutex.h"
#include "RE/G/GRefCountBase.h"
#include "RE/G/GStats.h"

namespace RE
{
	class GFxLoadUpdateSync : public GRefCountBase<GFxLoadUpdateSync, GFxStatMovieData::kGFxStatMD_Other_Mem>
	{
	public:
		~GFxLoadUpdateSync() override;  // 00

		// members
		GMutex mutex;  // 10
		void*  unk38;  // 38
		void*  unk40;  // 40
	};
	static_assert(sizeof(GFxLoadUpdateSync) == 0x48);
}
