#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTList.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/C/Crime.h"
#include "RE/N/NiSmartPointer.h"

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
		static_assert(sizeof(GetActorsFilter) == 0x8);

		static ProcessLists* GetSingleton();

		void ClearCachedFactionFightReactions() const;
		void StopCombatAndAlarmOnActor(Actor* a_actor, bool a_notAlarm);

		// members
		bool									runDetection;								   // 001
		bool									showDetectionStats;							   // 002
		std::uint8_t							pad003;										   // 003
		ActorHandle								statdetect;									   // 004
		bool									processHigh;								   // 008
		bool									processLow;									   // 009
		bool									processMHigh;								   // 00A
		bool									processMLow;								   // 00B
		std::uint16_t							unk00C;										   // 00C
		std::uint8_t							unk00E;										   // 00E
		std::uint8_t							pad00F;										   // 00F
		std::int32_t							numberHighActors;							   // 010
		float									unk014;										   // 014
		std::uint32_t							unk018;										   // 018
		float									removeExcessDeadTimer;						   // 01C
		BSSemaphore								movementSyncSema;							   // 020
		std::uint32_t							unk028;										   // 028
		std::uint32_t							pad02C;										   // 02C
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
		std::uint64_t							unk148;										   // 148
		std::uint64_t							unk150;										   // 150
		BSTArray<ObjectRefHandle>				tempShouldMoves;							   // 158
		BSSimpleList<ActorHandle>				unk170;										   // 170
		BSTArray<ActorHandle>					initPackageLocationsQueue;					   // 180
		mutable BSSpinLock						packageLocationsQueueLock;					   // 198
		BSTArray<ActorHandle>					initAnimPositionQueue;						   // 1A0
		BSTArray<BSTSmartPointer<SyncQueueObj>> syncPositionQueue;							   // 1B8
		float									playerActionCommentTimer;					   // 1D0
		float									playerKnockObjectCommentTimer;				   // 1D4
		std::uint32_t							currentLowActor;							   // 1D8
		std::uint32_t							currentMiddleHighActor;						   // 1DC
		std::uint32_t							currentMiddleLowActor;						   // 1E0
		bool									runSchedules;								   // 1E4
		bool									runMovement;								   // 1E5
		bool									runAnimations;								   // 1E6
		bool									updateActorsInPlayerCell;					   // 1E7
		std::uint64_t							unk1E8;										   // 1E8
	};
	static_assert(sizeof(ProcessLists) == 0x1F0);
}
