#pragma once

#include "RE/NiPlane.h"


namespace RE
{
	class NiFrustumPlanes
	{
	public:
		struct Planes
		{
			enum Plane
			{
				kNear,
				kFar,
				kLeft,
				kRight,
				kTop,
				kBottom,

				kTotal
			};
		};


		enum class ActivePlane : UInt32
		{
			kNear = 1 << 0,
			kFar = 1 << 1,
			kLeft = 1 << 2,
			kRight = 1 << 3,
			kTop = 1 << 4,
			kBottom = 1 << 5
		};


		// members
		NiPlane		cullingPlanes[Planes::kTotal];	// 00
		ActivePlane activePlanes;					// 60
		UInt32		basePlaneStates;				// 64
		UInt32		unk68;							// 68
		UInt32		unk6C;							// 6C
	};
	STATIC_ASSERT(sizeof(NiFrustumPlanes) == 0x70);
}
