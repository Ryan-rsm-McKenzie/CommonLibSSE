#pragma once

#include "RE/G/GImageBase.h"
#include "RE/G/GRefCountBaseNTS.h"

namespace RE
{
	class GImage :
		public GRefCountBaseNTS<GImage, GStatGroup::kGStat_Image_Mem>,
		public GImageBase
	{
	public:
		~GImage() override;  // 00
	};
	static_assert(sizeof(GImage) == 0x48);
}
