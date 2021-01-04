#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkMultiThreadCheck.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkStepInfo.h"
#include "RE/H/hkpSolverInfo.h"
#include "RE/H/hkpWorldCinfo.h"

namespace RE
{
	class hkCriticalSection;
	class hkdWorld;
	class hknpWorld;
	class hkpActionListener;
	class hkpBroadPhase;
	class hkpBroadPhaseBorder;
	class hkpBroadPhaseBorderListener;
	class hkpCollisionDispatcher;
	class hkpCollisionFilter;
	class hkpConstraintListener;
	class hkpContactImpulseLimitBreachedListener;
	class hkpContactListener;
	class hkpConvexListFilter;
	class hkpEntityEntityBroadPhaseListener;
	class hkpEntityListener;
	class hkpIslandActivationListener;
	class hkpIslandPostCollideListener;
	class hkpIslandPostIntegrateListener;
	class hkpPhantom;
	class hkpPhantomBroadPhaseListener;
	class hkpPhantomListener;
	class hkpSimulation;
	class hkpSimulationIsland;
	class hkpTreeWorldManager;
	class hkpTypedBroadPhaseDispatcher;
	class hkpWorldDeletionListener;
	class hkpWorldExtension;
	class hkpWorldMaintenanceMgr;
	class hkpWorldOperationQueue;
	class hkpWorldPostCollideListener;
	class hkpWorldPostIntegrateListener;
	class hkpWorldPostSimulationListener;
	class hkWorldMemoryAvailableWatchDog;
	struct hkpDebugInfoOnPendingOperationQueues;
	struct hkpMtThreadStructure;
	struct hkpProcessCollisionInput;
	struct hkpViolatedConstraintArray;
	struct hkpWorldRayCastInput;
	struct hkpWorldRayCastOutput;

	struct hkpWorldDynamicsStepInfo
	{
	public:
		// members
		hkStepInfo	  stepInfo;	   // 000
		hkpSolverInfo solverInfo;  // 010
	};
	static_assert(sizeof(hkpWorldDynamicsStepInfo) == 0x140);

	class hkpWorld : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpWorld;

		virtual ~hkpWorld();  // 00

		// override (hkReferencedObject)
		virtual void CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;	// 02

		inline void CastRay(const hkpWorldRayCastInput& a_input, hkpWorldRayCastOutput& a_output) const
		{
			using func_t = decltype(&hkpWorld::CastRay);
			REL::Relocation<func_t> func{ REL::ID(60551) };
			return func(this, a_input, a_output);
		}

		// members
		hkpSimulation*														  simulation;												  // 010
		std::uint64_t														  pad018;													  // 018
		hkVector4															  gravity;													  // 020
		hkpSimulationIsland*												  fixedIsland;												  // 030
		hkpRigidBody*														  fixedRigidBody;											  // 038
		hkArray<hkpSimulationIsland*>										  activeSimulationIslands;									  // 040
		hkArray<hkpSimulationIsland*>										  inactiveSimulationIslands;								  // 050
		hkArray<hkpSimulationIsland*>										  dirtySimulationIslands;									  // 060
		hkpWorldMaintenanceMgr*												  maintenanceMgr;											  // 070
		hkRefPtr<hkWorldMemoryAvailableWatchDog>							  memoryWatchDog;											  // 078
		bool																  assertOnRunningOutOfSolverMemory;							  // 080
		std::uint8_t														  pad081;													  // 081
		std::uint16_t														  pad082;													  // 082
		std::uint32_t														  pad084;													  // 084
		hkpBroadPhase*														  broadPhase;												  // 088
		hkpTreeWorldManager*												  kdTreeManager;											  // 090
		bool																  autoUpdateTree;											  // 098
		std::uint8_t														  pad099;													  // 099
		std::uint16_t														  pad09A;													  // 09A
		std::uint32_t														  pad09C;													  // 09C
		hkpTypedBroadPhaseDispatcher*										  broadPhaseDispatcher;										  // 0A0
		hkpPhantomBroadPhaseListener*										  phantomBroadPhaseListener;								  // 0A8
		hkpEntityEntityBroadPhaseListener*									  entityEntityBroadPhaseListener;							  // 0B0
		hkpBroadPhaseBorderListener*										  broadPhaseBorderListener;									  // 0B8
		hkpMtThreadStructure*												  multithreadedSimulationJobData;							  // 0C0
		hkpProcessCollisionInput*											  collisionInput;											  // 0C8
		hkpCollisionFilter*													  collisionFilter;											  // 0D0
		hkpCollisionDispatcher*												  collisionDispatcher;										  // 0D8
		hkpConvexListFilter*												  convexListFilter;											  // 0E0
		hkpWorldOperationQueue*												  pendingOperations;										  // 0E8
		std::int32_t														  pendingOperationsCount;									  // 0F0
		std::int32_t														  pendingBodyOperationsCount;								  // 0F4
		std::int32_t														  criticalOperationsLockCount;								  // 0F8
		std::int32_t														  criticalOperationsLockCountForPhantoms;					  // 0FC
		bool																  blockExecutingPendingOperations;							  // 100
		bool																  criticalOperationsAllowed;								  // 101
		std::uint16_t														  pad102;													  // 102
		std::uint32_t														  pad104;													  // 104
		hkpDebugInfoOnPendingOperationQueues*								  pendingOperationQueues;									  // 108
		std::int32_t														  pendingOperationQueueCount;								  // 110
		mutable hkMultiThreadCheck											  multiThreadCheck;											  // 114
		bool																  processActionsInSingleThread;								  // 120
		bool																  allowIntegrationOfIslandsWithoutConstraintsInASeparateJob;  // 121
		std::uint16_t														  pad122;													  // 122
		std::uint32_t														  minDesiredIslandSize;										  // 124
		hkCriticalSection*													  modifyConstraintCriticalSection;							  // 128
		std::int32_t														  isLocked;													  // 130
		std::uint32_t														  pad134;													  // 134
		hkCriticalSection*													  islandDirtyListCriticalSection;							  // 138
		hkCriticalSection*													  propertyMasterLock;										  // 140
		bool																  wantSimulationIslands;									  // 148
		bool																  useHybridBroadphase;										  // 149
		std::uint16_t														  pad14A;													  // 14A
		float																  snapCollisionToConvexEdgeThreshold;						  // 14C
		float																  snapCollisionToConcaveEdgeThreshold;						  // 150
		bool																  enableToiWeldRejection;									  // 154
		bool																  wantDeactivation;											  // 155
		bool																  shouldActivateOnRigidBodyTransformChange;					  // 156
		std::uint8_t														  pad153;													  // 157
		float																  deactivationReferenceDistance;							  // 158
		float																  toiCollisionResponseRotateNormal;							  // 15C
		std::int32_t														  maxSectorsPerMidphaseCollideTask;							  // 160
		std::int32_t														  maxSectorsPerNarrowphaseCollideTask;						  // 164
		bool																  processToisMultithreaded;									  // 168
		std::uint8_t														  pad169;													  // 169
		std::uint16_t														  pad16A;													  // 16A
		std::int32_t														  maxEntriesPerToiMidphaseCollideTask;						  // 16C
		std::int32_t														  maxEntriesPerToiNarrowphaseCollideTask;					  // 170
		std::int32_t														  maxNumToiCollisionPairsSinglethreaded;					  // 174
		stl::enumeration<hkpWorldCinfo::SimulationType, std::uint8_t>		  simulationType;											  // 178
		std::uint8_t														  pad179;													  // 179
		std::uint16_t														  pad17A;													  // 17A
		float																  numToisTillAllowedPenetrationSimplifiedToi;				  // 17C
		float																  numToisTillAllowedPenetrationToi;							  // 180
		float																  numToisTillAllowedPenetrationToiHigher;					  // 184
		float																  numToisTillAllowedPenetrationToiForced;					  // 188
		std::uint32_t														  lastEntityUID;											  // 18C
		std::uint32_t														  lastIslandUID;											  // 190
		std::uint32_t														  lastConstraintUID;										  // 194
		hkArray<hkpPhantom*>												  phantoms;													  // 198
		hkArray<hkpActionListener*>											  actionListeners;											  // 1A8
		hkArray<hkpEntityListener*>											  entityListeners;											  // 1B8
		hkArray<hkpPhantomListener*>										  phantomListeners;											  // 1C8
		hkArray<hkpConstraintListener*>										  constraintListeners;										  // 1D8
		hkArray<hkpWorldDeletionListener*>									  worldDeletionListeners;									  // 1E8
		hkArray<hkpIslandActivationListener*>								  islandActivationListeners;								  // 1F8
		hkArray<hkpWorldPostSimulationListener*>							  worldPostSimulationListeners;								  // 208
		hkArray<hkpWorldPostIntegrateListener*>								  worldPostIntegrateListeners;								  // 218
		hkArray<hkpWorldPostCollideListener*>								  worldPostCollideListeners;								  // 228
		hkArray<hkpIslandPostIntegrateListener*>							  islandPostIntegrateListeners;								  // 238
		hkArray<hkpIslandPostCollideListener*>								  islandPostCollideListeners;								  // 248
		hkArray<hkpContactListener*>										  contactListeners;											  // 258
		hkArray<hkpContactImpulseLimitBreachedListener*>					  contactImpulseLimitBreachedListeners;						  // 268
		hkArray<hkpWorldExtension*>											  worldExtensions;											  // 278
		hkpViolatedConstraintArray*											  violatedConstraintArray;									  // 288
		hkpBroadPhaseBorder*												  broadPhaseBorder;											  // 290
		hkdWorld*															  destructionWorld;											  // 298
		hknpWorld*															  npWorld;													  // 2A0
		std::uint64_t														  pad2A8;													  // 2A8
		hkpWorldDynamicsStepInfo											  dynamicsStepInfo;											  // 2B0
		hkVector4															  broadPhaseExtents[2];										  // 3F0
		std::int32_t														  broadPhaseNumMarkers;										  // 410
		std::int32_t														  sizeOfToiEventQueue;										  // 414
		std::int32_t														  broadPhaseQuerySize;										  // 418
		std::int32_t														  broadPhaseUpdateSize;										  // 41C
		stl::enumeration<hkpWorldCinfo::ContactPointGeneration, std::uint8_t> contactPointGeneration;									  // 420
		std::uint8_t														  pad421;													  // 421
		std::uint16_t														  pad422;													  // 422
		std::uint32_t														  pad424;													  // 424
		std::uint64_t														  pad428;													  // 428
	};
	static_assert(sizeof(hkpWorld) == 0x430);
}
