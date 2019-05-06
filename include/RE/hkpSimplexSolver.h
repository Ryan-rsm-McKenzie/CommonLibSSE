#pragma once

#include "RE/hkVector4.h"  // hkVector4


namespace RE
{
	struct hkpSurfaceConstraintInfo
	{
		hkVector4	plane;						// 00
		hkVector4	velocity;					// 10
		float		staticFriction;				// 20
		float		extraUpStaticFriction;		// 24
		float		extraDownStaticFriction;	// 28
		float		dynamicFriction;			// 2C
		SInt32		priority;					// 30
		UInt32		pad34;						// 34
		UInt64		pad38;						// 38
	};
	STATIC_ASSERT(sizeof(hkpSurfaceConstraintInfo) == 0x40);


	struct hkpSimplexSolverInput
	{
		hkVector4					position;			// 00
		hkVector4					velocity;			// 10
		hkVector4					maxSurfaceVelocity;	// 20
		hkVector4					upVector;			// 30
		float						deltaTime;			// 40
		float						minDeltaTime;		// 44
		hkpSurfaceConstraintInfo*	constraints;		// 48
		SInt32						numConstraints;		// 50
		UInt32						pad54;				// 54
		UInt64						pad58;				// 58
	};
	STATIC_ASSERT(sizeof(hkpSimplexSolverInput) == 0x60);
}
