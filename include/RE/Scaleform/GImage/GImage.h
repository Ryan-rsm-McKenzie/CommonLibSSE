#pragma once

#include "RE/Scaleform/GImage/GImageBase.h"
#include "RE/Scaleform/GRefCount/GRefCountBaseNTS.h"


namespace RE
{
	class GImage :
		public GRefCountBaseNTS<GImage, GStatGroup::kGStat_Image_Mem>,
		public GImageBase
	{
	public:
		virtual ~GImage();	// 00
	};
	STATIC_ASSERT(sizeof(GImage) == 0x48);
}
