#pragma once

#include "RE/H/hkVector4.h"

namespace RE
{
	struct hkpSurfaceInfo
	{
		enum class SupportedState
		{
			kUnsupported = 0,
			kSliding = 1,
			kSupported = 2
		};

		stl::enumeration<SupportedState, std::uint32_t> supportedState;         // 00
		std::uint32_t                                   pad04;                  // 04
		std::uint64_t                                   pad08;                  // 08
		hkVector4                                       surfaceNormal;          // 10
		hkVector4                                       surfaceVelocity;        // 20
		float                                           surfaceDistanceExcess;  // 30
		bool                                            surfaceIsDynamic;       // 34
		std::uint8_t                                    pad35;                  // 35
		std::uint16_t                                   pad36;                  // 36
		std::uint64_t                                   pad38;                  // 38
	};
	static_assert(sizeof(hkpSurfaceInfo) == 0x40);
}
