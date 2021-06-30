#pragma once

#include "RE/H/hkAabb.h"
#include "RE/H/hkRefPtr.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkVector4.h"

namespace RE
{
	class hkpCollisionFilter;
	class hkpConvexListFilter;
	class hkWorldMemoryAvailableWatchDog;

	class hkpWorldCinfo : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpWorldCinfo;

		enum class SolverType
		{
			kInvalid,
			k2Iters_Soft,
			k2Iters_Medium,
			k2Iters_Hard,
			k4Iters_Soft,
			k4Iters_Medium,
			k4Iters_Hard,
			k8Iters_Soft,
			k8Iters_Medium,
			k8Iters_Hard,

			kTotal
		};

		enum class SimulationType
		{
			kInvalid,
			kDiscrete,
			kContinuous,
			kMultithreaded,
		};

		enum class ContactPointGeneration
		{
			kAcceptAlways,
			kRejectDubious,
			kRejectMany
		};

		enum class BroadPhaseBorderBehaviour
		{
			kAssert,
			kFixEntity,
			kRemoveEntity,
			kDoNothing
		};

		enum class TreeUpdateType
		{
			kActive,
			kAll
		};

		~hkpWorldCinfo() override;  // 00

		// members
		hkVector4                                                gravity;                                                    // 010
		std::int32_t                                             broadPhaseQuerySize;                                        // 020
		float                                                    contactRestingVelocity;                                     // 024
		stl::enumeration<BroadPhaseBorderBehaviour, std::int8_t> broadPhaseBorderBehaviour;                                  // 028
		bool                                                     mtPostponeAndSortBroadPhaseBorderCallbacks;                 // 029
		std::uint16_t                                            pad02A;                                                     // 02A
		std::uint32_t                                            pad02C;                                                     // 02C
		hkAabb                                                   broadPhaseWorldAabb;                                        // 030
		bool                                                     useKdTree;                                                  // 050
		bool                                                     useMultipleTree;                                            // 051
		stl::enumeration<TreeUpdateType, std::int8_t>            treeUpdateType;                                             // 052
		bool                                                     autoUpdateKdTree;                                           // 053
		float                                                    collisionTolerance;                                         // 054
		hkRefPtr<hkpCollisionFilter>                             collisionFilter;                                            // 058
		hkRefPtr<hkpConvexListFilter>                            convexListFilter;                                           // 060
		float                                                    expectedMaxLinearVelocity;                                  // 064
		std::int32_t                                             sizeOfToiEventQueue;                                        // 068
		float                                                    expectedMinPsiDeltaTime;                                    // 06C
		hkRefPtr<hkWorldMemoryAvailableWatchDog>                 memoryWatchDog;                                             // 070
		std::int32_t                                             broadPhaseNumMarkers;                                       // 080
		stl::enumeration<ContactPointGeneration, std::int8_t>    contactPointGeneration;                                     // 084
		bool                                                     allowToSkipConfirmedCallbacks;                              // 085
		bool                                                     useHybridBroadphase;                                        // 086
		std::uint8_t                                             pad087;                                                     // 087
		float                                                    solverTau;                                                  // 088
		float                                                    solverDamp;                                                 // 08C
		std::int32_t                                             solverIterations;                                           // 090
		std::int32_t                                             solverMicrosteps;                                           // 094
		float                                                    maxConstraintViolation;                                     // 098
		bool                                                     forceCoherentConstraintOrderingInSolver;                    // 09C
		std::uint8_t                                             pad09D;                                                     // 09D
		std::uint16_t                                            pad09E;                                                     // 09E
		float                                                    snapCollisionToConvexEdgeThreshold;                         // 0A0
		float                                                    snapCollisionToConcaveEdgeThreshold;                        // 0A4
		bool                                                     enableToiWeldRejection;                                     // 0A8
		bool                                                     enableDeprecatedWelding;                                    // 0A9
		std::uint16_t                                            pad0AA;                                                     // 0AA
		float                                                    iterativeLinearCastEarlyOutDistance;                        // 0AC
		std::int32_t                                             iterativeLinearCastMaxIterations;                           // 0B0
		std::uint8_t                                             deactivationNumInactiveFramesSelectFlag0;                   // 0B4
		std::uint8_t                                             deactivationNumInactiveFramesSelectFlag1;                   // 0B5
		std::uint8_t                                             deactivationIntegrateCounter;                               // 0B6
		bool                                                     shouldActivateOnRigidBodyTransformChange;                   // 0B7
		float                                                    deactivationReferenceDistance;                              // 0B8
		float                                                    toiCollisionResponseRotateNormal;                           // 0BC
		std::int32_t                                             maxSectorsPerMidphaseCollideTask;                           // 0C0
		std::int32_t                                             maxSectorsPerNarrowphaseCollideTask;                        // 0C4
		bool                                                     processToisMultithreaded;                                   // 0C8
		std::uint8_t                                             pad0C9;                                                     // 0C9
		std::uint16_t                                            pad0CA;                                                     // 0CA
		std::int32_t                                             maxEntriesPerToiMidphaseCollideTask;                        // 0CC
		std::int32_t                                             maxEntriesPerToiNarrowphaseCollideTask;                     // 0D0
		std::int32_t                                             maxNumToiCollisionPairsSinglethreaded;                      // 0D4
		float                                                    numToisTillAllowedPenetrationSimplifiedToi;                 // 0D8
		float                                                    numToisTillAllowedPenetrationToi;                           // 0DC
		float                                                    numToisTillAllowedPenetrationToiHigher;                     // 0E0
		float                                                    numToisTillAllowedPenetrationToiForced;                     // 0E4
		bool                                                     enableDeactivation;                                         // 0E8
		stl::enumeration<SimulationType, std::int8_t>            simulationType;                                             // 0E9
		bool                                                     enableSimulationIslands;                                    // 0EA
		std::uint8_t                                             pad0EB;                                                     // 0EB
		std::uint32_t                                            minDesiredIslandSize;                                       // 0EC
		bool                                                     processActionsInSingleThread;                               // 0F0
		bool                                                     allowIntegrationOfIslandsWithoutConstraintsInASeparateJob;  // 0F1
		std::uint16_t                                            pad0F2;                                                     // 0F2
		float                                                    frameMarkerPsiSnap;                                         // 0F4
		bool                                                     fireCollisionCallbacks;                                     // 0F8
		std::uint8_t                                             pad0F9;                                                     // 0F9
		std::uint16_t                                            pad0FA;                                                     // 0FA
		std::uint32_t                                            pad0FC;                                                     // 0FC
	};
	static_assert(sizeof(hkpWorldCinfo) == 0x100);
}
