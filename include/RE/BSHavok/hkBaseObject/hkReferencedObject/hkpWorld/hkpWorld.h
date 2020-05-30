#pragma once

#include "RE/hkArray.h"
#include "RE/hkMultiThreadCheck.h"
#include "RE/hkReferencedObject.h"
#include "RE/hkStepInfo.h"
#include "RE/hkpSolverInfo.h"
#include "RE/hkpWorldCinfo.h"


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


	struct hkpWorldDynamicsStepInfo
	{
		hkStepInfo	  stepInfo;	   // 000
		hkpSolverInfo solverInfo;  // 010
	};
	STATIC_ASSERT(sizeof(hkpWorldDynamicsStepInfo) == 0x140);


	class hkpWorld : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpWorld;


		virtual ~hkpWorld();  // 00

		// override (hkReferencedObject)
		virtual void CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;	// 02


		// members
		hkpSimulation*									 simulation;												 // 010
		UInt64											 pad018;													 // 018
		hkVector4										 gravity;													 // 020
		hkpSimulationIsland*							 fixedIsland;												 // 030
		hkpRigidBody*									 fixedRigidBody;											 // 038
		hkArray<hkpSimulationIsland*>					 activeSimulationIslands;									 // 040
		hkArray<hkpSimulationIsland*>					 inactiveSimulationIslands;									 // 050
		hkArray<hkpSimulationIsland*>					 dirtySimulationIslands;									 // 060
		hkpWorldMaintenanceMgr*							 maintenanceMgr;											 // 070
		hkRefPtr<hkWorldMemoryAvailableWatchDog>		 memoryWatchDog;											 // 078
		bool											 assertOnRunningOutOfSolverMemory;							 // 080
		UInt8											 pad081;													 // 081
		UInt16											 pad082;													 // 082
		UInt32											 pad084;													 // 084
		hkpBroadPhase*									 broadPhase;												 // 088
		hkpTreeWorldManager*							 kdTreeManager;												 // 090
		bool											 autoUpdateTree;											 // 098
		UInt8											 pad099;													 // 099
		UInt16											 pad09A;													 // 09A
		UInt32											 pad09C;													 // 09C
		hkpTypedBroadPhaseDispatcher*					 broadPhaseDispatcher;										 // 0A0
		hkpPhantomBroadPhaseListener*					 phantomBroadPhaseListener;									 // 0A8
		hkpEntityEntityBroadPhaseListener*				 entityEntityBroadPhaseListener;							 // 0B0
		hkpBroadPhaseBorderListener*					 broadPhaseBorderListener;									 // 0B8
		hkpMtThreadStructure*							 multithreadedSimulationJobData;							 // 0C0
		hkpProcessCollisionInput*						 collisionInput;											 // 0C8
		hkpCollisionFilter*								 collisionFilter;											 // 0D0
		hkpCollisionDispatcher*							 collisionDispatcher;										 // 0D8
		hkpConvexListFilter*							 convexListFilter;											 // 0E0
		hkpWorldOperationQueue*							 pendingOperations;											 // 0E8
		SInt32											 pendingOperationsCount;									 // 0F0
		SInt32											 pendingBodyOperationsCount;								 // 0F4
		SInt32											 criticalOperationsLockCount;								 // 0F8
		SInt32											 criticalOperationsLockCountForPhantoms;					 // 0FC
		bool											 blockExecutingPendingOperations;							 // 100
		bool											 criticalOperationsAllowed;									 // 101
		UInt16											 pad102;													 // 102
		UInt32											 pad104;													 // 104
		hkpDebugInfoOnPendingOperationQueues*			 pendingOperationQueues;									 // 108
		SInt32											 pendingOperationQueueCount;								 // 110
		mutable hkMultiThreadCheck						 multiThreadCheck;											 // 114
		bool											 processActionsInSingleThread;								 // 120
		bool											 allowIntegrationOfIslandsWithoutConstraintsInASeparateJob;	 // 121
		UInt16											 pad122;													 // 122
		UInt32											 minDesiredIslandSize;										 // 124
		hkCriticalSection*								 modifyConstraintCriticalSection;							 // 128
		SInt32											 isLocked;													 // 130
		UInt32											 pad134;													 // 134
		hkCriticalSection*								 islandDirtyListCriticalSection;							 // 138
		hkCriticalSection*								 propertyMasterLock;										 // 140
		bool											 wantSimulationIslands;										 // 148
		bool											 useHybridBroadphase;										 // 149
		UInt16											 pad14A;													 // 14A
		float											 snapCollisionToConvexEdgeThreshold;						 // 14C
		float											 snapCollisionToConcaveEdgeThreshold;						 // 150
		bool											 enableToiWeldRejection;									 // 154
		bool											 wantDeactivation;											 // 155
		bool											 shouldActivateOnRigidBodyTransformChange;					 // 156
		UInt8											 pad153;													 // 157
		float											 deactivationReferenceDistance;								 // 158
		float											 toiCollisionResponseRotateNormal;							 // 15C
		SInt32											 maxSectorsPerMidphaseCollideTask;							 // 160
		SInt32											 maxSectorsPerNarrowphaseCollideTask;						 // 164
		bool											 processToisMultithreaded;									 // 168
		UInt8											 pad169;													 // 169
		UInt16											 pad16A;													 // 16A
		SInt32											 maxEntriesPerToiMidphaseCollideTask;						 // 16C
		SInt32											 maxEntriesPerToiNarrowphaseCollideTask;					 // 170
		SInt32											 maxNumToiCollisionPairsSinglethreaded;						 // 174
		hkpWorldCinfo::SimulationType					 simulationType;											 // 178
		UInt8											 pad179;													 // 179
		UInt16											 pad17A;													 // 17A
		float											 numToisTillAllowedPenetrationSimplifiedToi;				 // 17C
		float											 numToisTillAllowedPenetrationToi;							 // 180
		float											 numToisTillAllowedPenetrationToiHigher;					 // 184
		float											 numToisTillAllowedPenetrationToiForced;					 // 188
		UInt32											 lastEntityUID;												 // 18C
		UInt32											 lastIslandUID;												 // 190
		UInt32											 lastConstraintUID;											 // 194
		hkArray<hkpPhantom*>							 phantoms;													 // 198
		hkArray<hkpActionListener*>						 actionListeners;											 // 1A8
		hkArray<hkpEntityListener*>						 entityListeners;											 // 1B8
		hkArray<hkpPhantomListener*>					 phantomListeners;											 // 1C8
		hkArray<hkpConstraintListener*>					 constraintListeners;										 // 1D8
		hkArray<hkpWorldDeletionListener*>				 worldDeletionListeners;									 // 1E8
		hkArray<hkpIslandActivationListener*>			 islandActivationListeners;									 // 1F8
		hkArray<hkpWorldPostSimulationListener*>		 worldPostSimulationListeners;								 // 208
		hkArray<hkpWorldPostIntegrateListener*>			 worldPostIntegrateListeners;								 // 218
		hkArray<hkpWorldPostCollideListener*>			 worldPostCollideListeners;									 // 228
		hkArray<hkpIslandPostIntegrateListener*>		 islandPostIntegrateListeners;								 // 238
		hkArray<hkpIslandPostCollideListener*>			 islandPostCollideListeners;								 // 248
		hkArray<hkpContactListener*>					 contactListeners;											 // 258
		hkArray<hkpContactImpulseLimitBreachedListener*> contactImpulseLimitBreachedListeners;						 // 268
		hkArray<hkpWorldExtension*>						 worldExtensions;											 // 278
		hkpViolatedConstraintArray*						 violatedConstraintArray;									 // 288
		hkpBroadPhaseBorder*							 broadPhaseBorder;											 // 290
		hkdWorld*										 destructionWorld;											 // 298
		hknpWorld*										 npWorld;													 // 2A0
		UInt64											 pad2A8;													 // 2A8
		hkpWorldDynamicsStepInfo						 dynamicsStepInfo;											 // 2B0
		hkVector4										 broadPhaseExtents[2];										 // 3F0
		SInt32											 broadPhaseNumMarkers;										 // 410
		SInt32											 sizeOfToiEventQueue;										 // 414
		SInt32											 broadPhaseQuerySize;										 // 418
		SInt32											 broadPhaseUpdateSize;										 // 41C
		hkpWorldCinfo::ContactPointGeneration			 contactPointGeneration;									 // 420
		UInt8											 pad421;													 // 421
		UInt16											 pad422;													 // 422
		UInt32											 pad424;													 // 424
		UInt64											 pad428;													 // 428
	};
	STATIC_ASSERT(sizeof(hkpWorld) == 0x430);
}
