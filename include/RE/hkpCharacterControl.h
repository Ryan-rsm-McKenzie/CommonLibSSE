#pragma once

#include "RE/hkVector4.h"  // hkVector4


namespace RE
{
	struct hkpSurfaceInfo
	{
		enum class SupportedState : UInt32
		{
			kUnsupported = 0,
			kSliding = 1,
			kSupported = 2
		};


		SupportedState	supportedState;			// 00
		UInt32			pad04;					// 04
		UInt64			pad08;					// 08
		hkVector4		surfaceNormal;			// 10
		hkVector4		surfaceVelocity;		// 20
		float			surfaceDistanceExcess;	// 30
		bool			surfaceIsDynamic;		// 34
		UInt8			pad35;					// 35
		UInt16			pad36;					// 36
		UInt64			pad38;					// 38
	};
	STATIC_ASSERT(sizeof(hkpSurfaceInfo) == 0x40);
}
