#pragma once

#include "RE/hkBaseTypes.h"
#include "RE/hkVector4.h"


namespace RE
{
	struct hkpSolverInfo
	{
		struct DeactivationClasses
		{
			enum DeactivationClass : UInt32
			{
				kInvalid,
				kOff,
				kLow,
				kMedium,
				kHigh,
				kAggressive,

				kTotal
			};
		};
		using DeactivationClass = DeactivationClasses::DeactivationClass;


		struct DeactivationInfo
		{
			float  linearVelocityThresholdInv;		// 00
			float  angularVelocityThresholdInv;		// 04
			float  slowObjectVelocityMultiplier;	// 08
			float  relativeSleepVelocityThreshold;	// 0C
			float  maxDistSqrd[2];					// 10
			hkHalf maxRotSqrd[2];					// 18
		};
		STATIC_ASSERT(sizeof(DeactivationInfo) == 0x1C);


		// members
		alignas(0x10) float one;									   // 000
		float			 tau;										   // 004
		float			 damping;									   // 008
		float			 frictionTau;								   // 00C
		hkVector4		 globalAccelerationPerSubStep;				   // 010
		hkVector4		 globalAccelerationPerStep;					   // 020
		hkVector4		 integrateVelocityFactor;					   // 030
		hkVector4		 invIntegrateVelocityFactor;				   // 040
		float			 dampDivTau;								   // 050
		float			 tauDivDamp;								   // 054
		float			 dampDivFrictionTau;						   // 058
		float			 frictionTauDivDamp;						   // 05C
		float			 contactRestingVelocity;					   // 060
		DeactivationInfo deactivationInfo[DeactivationClass::kTotal];  // 064
		float			 deltaTime;									   // 10C
		float			 invDeltaTime;								   // 110
		SInt32			 numSteps;									   // 114
		SInt32			 numMicroSteps;								   // 118
		float			 invNumMicroSteps;							   // 11C
		float			 invNumSteps;								   // 120
		bool			 forceCoherentConstraintOrderingInSolver;	   // 124
		UInt8			 deactivationNumInactiveFramesSelectFlag[2];   // 125
		UInt8			 deactivationIntegrateCounter;				   // 127
		float			 maxConstraintViolationSqrd;				   // 128
		UInt32			 pad12C;									   // 12C
	};
	STATIC_ASSERT(sizeof(hkpSolverInfo) == 0x130);
}
