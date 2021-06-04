#pragma once

#include "RE/H/hkBaseTypes.h"
#include "RE/H/hkVector4.h"

namespace RE
{
	struct hkpSolverInfo
	{
		struct DeactivationClasses
		{
			enum DeactivationClass : std::uint32_t
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
			float  linearVelocityThresholdInv;      // 00
			float  angularVelocityThresholdInv;     // 04
			float  slowObjectVelocityMultiplier;    // 08
			float  relativeSleepVelocityThreshold;  // 0C
			float  maxDistSqrd[2];                  // 10
			hkHalf maxRotSqrd[2];                   // 18
		};
		static_assert(sizeof(DeactivationInfo) == 0x1C);

		// members
		alignas(0x10) float one;                                       // 000
		float            tau;                                          // 004
		float            damping;                                      // 008
		float            frictionTau;                                  // 00C
		hkVector4        globalAccelerationPerSubStep;                 // 010
		hkVector4        globalAccelerationPerStep;                    // 020
		hkVector4        integrateVelocityFactor;                      // 030
		hkVector4        invIntegrateVelocityFactor;                   // 040
		float            dampDivTau;                                   // 050
		float            tauDivDamp;                                   // 054
		float            dampDivFrictionTau;                           // 058
		float            frictionTauDivDamp;                           // 05C
		float            contactRestingVelocity;                       // 060
		DeactivationInfo deactivationInfo[DeactivationClass::kTotal];  // 064
		float            deltaTime;                                    // 10C
		float            invDeltaTime;                                 // 110
		std::int32_t     numSteps;                                     // 114
		std::int32_t     numMicroSteps;                                // 118
		float            invNumMicroSteps;                             // 11C
		float            invNumSteps;                                  // 120
		bool             forceCoherentConstraintOrderingInSolver;      // 124
		std::uint8_t     deactivationNumInactiveFramesSelectFlag[2];   // 125
		std::uint8_t     deactivationIntegrateCounter;                 // 127
		float            maxConstraintViolationSqrd;                   // 128
		std::uint32_t    pad12C;                                       // 12C
	};
	static_assert(sizeof(hkpSolverInfo) == 0x130);
}
