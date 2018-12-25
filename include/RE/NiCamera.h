#pragma once

#include "skse64/NiObjects.h"  // NiAVObject, NiFrustum

#include "RE/NiRect.h"  // NiRect


namespace RE
{
	class NiCamera : public NiAVObject
	{
	public:
		float			worldToCam[4][4];	// 110
		NiFrustum		frustum;			// 150
		float			minNearPlaneDist;	// 16C
		float			maxFarNearRatio;	// 170
		NiRect<float>	port;				// 174
		float			lodAdjust;			// 184
	};
	STATIC_ASSERT(sizeof(NiCamera) == 0x188);
}
