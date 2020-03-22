#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSTArray.h"
#include "RE/BSTList.h"
#include "RE/BSTSingleton.h"
#include "RE/BSTSmartPointer.h"
#include "RE/Crime.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class Actor;
	class BSTempEffect;
	class SyncQueueObj;


	class ProcessLists : public BSTSingletonSDM<ProcessLists>
	{
	public:
		class GetActorsFilter
		{
		public:
			inline static constexpr auto RTTI = RTTI_ProcessLists__GetActorsFilter;


			virtual ~GetActorsFilter();	 // 00

			// add
			virtual bool IsValid(Actor* a_actor) = 0;  // 01
		};
		STATIC_ASSERT(sizeof(GetActorsFilter) == 0x8);


		static ProcessLists* GetSingleton();

		void StopCombatAndAlarmOnActor(Actor* a_actor, bool a_dontEndAlarm);


		// members
		bool									runDetection;								   // 001
		bool									showDetectionStats;							   // 002
		UInt8									pad003;										   // 003
		ActorHandle								statdetect;									   // 004
		bool									processHigh;								   // 008
		bool									processLow;									   // 009
		bool									processMHigh;								   // 00A
		bool									processMLow;								   // 00B
		UInt16									unk00C;										   // 00C
		UInt8									unk00E;										   // 00E
		UInt8									pad00F;										   // 00F
		SInt32									numberHighActors;							   // 010
		float									unk014;										   // 014
		UInt32									unk018;										   // 018
		float									removeExcessDeadTimer;						   // 01C
		BSSemaphore								movementSyncSema;							   // 020
		UInt32									unk028;										   // 028
		UInt32									pad02C;										   // 02C
		BSTArray<ActorHandle>					highActorHandles;							   // 030
		BSTArray<ActorHandle>					lowActorHandles;							   // 048
		BSTArray<ActorHandle>					middleHighActorHandles;						   // 060
		BSTArray<ActorHandle>					middleLowActorHandles;						   // 078
		BSTArray<ActorHandle>*					allProcesses[4];							   // 090
		BSSimpleList<Crime*>*					globalCrimes[PackageNS::CRIME_TYPES::kTotal];  // 0B0
		BSTArray<NiPointer<BSTempEffect>>		globalTempEffects;							   // 0E8
		mutable BSSpinLock						globalEffectsLock;							   // 100
		BSTArray<NiPointer<BSTempEffect>>		magicEffects;								   // 108
		mutable BSSpinLock						magicEffectsLock;							   // 120
		BSTArray<NiPointer<BSTempEffect>>		interfaceEffects;							   // 128
		mutable BSSpinLock						interfaceEffectsLock;						   // 140
		UInt64									unk148;										   // 148
		UInt64									unk150;										   // 150
		BSTArray<ObjectRefHandle>				tempShouldMoves;							   // 158
		BSSimpleList<ActorHandle>				unk170;										   // 170
		BSTArray<ActorHandle>					initPackageLocationsQueue;					   // 180
		mutable BSSpinLock						packageLocationsQueueLock;					   // 198
		BSTArray<ActorHandle>					initAnimPositionQueue;						   // 1A0
		BSTArray<BSTSmartPointer<SyncQueueObj>> syncPositionQueue;							   // 1B8
		float									playerActionCommentTimer;					   // 1D0
		float									playerKnockObjectCommentTimer;				   // 1D4
		UInt32									currentLowActor;							   // 1D8
		UInt32									currentMiddleHighActor;						   // 1DC
		UInt32									currentMiddleLowActor;						   // 1E0
		bool									runSchedules;								   // 1E4
		bool									runMovement;								   // 1E5
		bool									runAnimations;								   // 1E6
		bool									updateActorsInPlayerCell;					   // 1E7
		UInt64									unk1E8;										   // 1E8
	};
	STATIC_ASSERT(sizeof(ProcessLists) == 0x1F0);
}
