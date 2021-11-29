#pragma once

#include "RE/H/hkVector4.h"

namespace RE
{
	struct hkpSurfaceConstraintInfo
	{
		hkVector4     plane;                    // 00
		hkVector4     velocity;                 // 10
		float         staticFriction;           // 20
		float         extraUpStaticFriction;    // 24
		float         extraDownStaticFriction;  // 28
		float         dynamicFriction;          // 2C
		std::int32_t  priority;                 // 30
		std::uint32_t pad34;                    // 34
		std::uint64_t pad38;                    // 38
	};
	static_assert(sizeof(hkpSurfaceConstraintInfo) == 0x40);

	struct hkpSimplexSolverInput
	{
		hkVector4                 position;            // 00
		hkVector4                 velocity;            // 10
		hkVector4                 maxSurfaceVelocity;  // 20
		hkVector4                 upVector;            // 30
		float                     deltaTime;           // 40
		float                     minDeltaTime;        // 44
		hkpSurfaceConstraintInfo* constraints;         // 48
		std::int32_t              numConstraints;      // 50
		std::uint32_t             pad54;               // 54
		std::uint64_t             pad58;               // 58
	};
	static_assert(sizeof(hkpSimplexSolverInput) == 0x60);
}
