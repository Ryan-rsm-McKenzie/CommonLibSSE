#pragma once

#include "RE/N/NiPlane.h"

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

		enum class ActivePlane
		{
			kNear = 1 << 0,
			kFar = 1 << 1,
			kLeft = 1 << 2,
			kRight = 1 << 3,
			kTop = 1 << 4,
			kBottom = 1 << 5
		};

		// members
		NiPlane                                      cullingPlanes[Planes::kTotal];  // 00
		stl::enumeration<ActivePlane, std::uint32_t> activePlanes;                   // 60
		std::uint32_t                                basePlaneStates;                // 64
		std::uint32_t                                unk68;                          // 68
		std::uint32_t                                unk6C;                          // 6C
	};
	static_assert(sizeof(NiFrustumPlanes) == 0x70);
}
