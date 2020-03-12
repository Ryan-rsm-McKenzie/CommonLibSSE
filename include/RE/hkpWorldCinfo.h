#pragma once

#include "RE/hkAabb.h"
#include "RE/hkRefPtr.h"
#include "RE/hkReferencedObject.h"
#include "RE/hkVector4.h"


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


		enum class SimulationType : SInt8
		{
			kInvalid,
			kDiscrete,
			kContinuous,
			kMultithreaded,
		};


		enum class SimulationType32 : SInt32
		{
			kInvalid,
			kDiscrete,
			kContinuous,
			kMultithreaded,
		};


		enum class ContactPointGeneration : SInt8
		{
			kAcceptAlways,
			kRejectDubious,
			kRejectMany
		};


		enum class BroadPhaseBorderBehaviour : SInt8
		{
			kAssert,
			kFixEntity,
			kRemoveEntity,
			kDoNothing
		};


		enum class TreeUpdateType : SInt8
		{
			kActive,
			kAll
		};


		virtual ~hkpWorldCinfo();  // 00


		// members
		hkVector4								 gravity;													 // 010
		SInt32									 broadPhaseQuerySize;										 // 020
		float									 contactRestingVelocity;									 // 024
		BroadPhaseBorderBehaviour				 broadPhaseBorderBehaviour;									 // 028
		bool									 mtPostponeAndSortBroadPhaseBorderCallbacks;				 // 029
		UInt16									 pad02A;													 // 02A
		UInt32									 pad02C;													 // 02C
		hkAabb									 broadPhaseWorldAabb;										 // 030
		bool									 useKdTree;													 // 050
		bool									 useMultipleTree;											 // 051
		TreeUpdateType							 treeUpdateType;											 // 052
		bool									 autoUpdateKdTree;											 // 053
		float									 collisionTolerance;										 // 054
		hkRefPtr<hkpCollisionFilter>			 collisionFilter;											 // 058
		hkRefPtr<hkpConvexListFilter>			 convexListFilter;											 // 060
		float									 expectedMaxLinearVelocity;									 // 064
		SInt32									 sizeOfToiEventQueue;										 // 068
		float									 expectedMinPsiDeltaTime;									 // 06C
		hkRefPtr<hkWorldMemoryAvailableWatchDog> memoryWatchDog;											 // 070
		SInt32									 broadPhaseNumMarkers;										 // 080
		ContactPointGeneration					 contactPointGeneration;									 // 084
		bool									 allowToSkipConfirmedCallbacks;								 // 085
		bool									 useHybridBroadphase;										 // 086
		UInt8									 pad087;													 // 087
		float									 solverTau;													 // 088
		float									 solverDamp;												 // 08C
		SInt32									 solverIterations;											 // 090
		SInt32									 solverMicrosteps;											 // 094
		float									 maxConstraintViolation;									 // 098
		bool									 forceCoherentConstraintOrderingInSolver;					 // 09C
		UInt8									 pad09D;													 // 09D
		UInt16									 pad09E;													 // 09E
		float									 snapCollisionToConvexEdgeThreshold;						 // 0A0
		float									 snapCollisionToConcaveEdgeThreshold;						 // 0A4
		bool									 enableToiWeldRejection;									 // 0A8
		bool									 enableDeprecatedWelding;									 // 0A9
		UInt16									 pad0AA;													 // 0AA
		float									 iterativeLinearCastEarlyOutDistance;						 // 0AC
		SInt32									 iterativeLinearCastMaxIterations;							 // 0B0
		UInt8									 deactivationNumInactiveFramesSelectFlag0;					 // 0B4
		UInt8									 deactivationNumInactiveFramesSelectFlag1;					 // 0B5
		UInt8									 deactivationIntegrateCounter;								 // 0B6
		bool									 shouldActivateOnRigidBodyTransformChange;					 // 0B7
		float									 deactivationReferenceDistance;								 // 0B8
		float									 toiCollisionResponseRotateNormal;							 // 0BC
		SInt32									 maxSectorsPerMidphaseCollideTask;							 // 0C0
		SInt32									 maxSectorsPerNarrowphaseCollideTask;						 // 0C4
		bool									 processToisMultithreaded;									 // 0C8
		UInt8									 pad0C9;													 // 0C9
		UInt16									 pad0CA;													 // 0CA
		SInt32									 maxEntriesPerToiMidphaseCollideTask;						 // 0CC
		SInt32									 maxEntriesPerToiNarrowphaseCollideTask;					 // 0D0
		SInt32									 maxNumToiCollisionPairsSinglethreaded;						 // 0D4
		float									 numToisTillAllowedPenetrationSimplifiedToi;				 // 0D8
		float									 numToisTillAllowedPenetrationToi;							 // 0DC
		float									 numToisTillAllowedPenetrationToiHigher;					 // 0E0
		float									 numToisTillAllowedPenetrationToiForced;					 // 0E4
		bool									 enableDeactivation;										 // 0E8
		SimulationType							 simulationType;											 // 0E9
		bool									 enableSimulationIslands;									 // 0EA
		UInt8									 pad0EB;													 // 0EB
		UInt32									 minDesiredIslandSize;										 // 0EC
		bool									 processActionsInSingleThread;								 // 0F0
		bool									 allowIntegrationOfIslandsWithoutConstraintsInASeparateJob;	 // 0F1
		UInt16									 pad0F2;													 // 0F2
		float									 frameMarkerPsiSnap;										 // 0F4
		bool									 fireCollisionCallbacks;									 // 0F8
		UInt8									 pad0F9;													 // 0F9
		UInt16									 pad0FA;													 // 0FA
		UInt32									 pad0FC;													 // 0FC
	};
	STATIC_ASSERT(sizeof(hkpWorldCinfo) == 0x100);
}
