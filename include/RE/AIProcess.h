#pragma once

#include <type_traits>

#include "RE/ActorPackage.h"
#include "RE/BSTArray.h"
#include "RE/BSTList.h"


namespace RE
{
	enum class RESET_3D_FLAGS : UInt8;
	class Actor;
	class bhkCharacterController;
	class HighProcess;
	class TESForm;
	struct HighProcessData;
	struct MiddleHighProcessData;


	enum class PROCESS_TYPE : UInt8
	{
		kNone = static_cast<std::underlying_type_t<PROCESS_TYPE>>(-1),
		kHigh = 0,
		kMiddleHigh = 1,
		kMiddleLow = 2,
		kLow = 3
	};


	class MiddleLowProcessData
	{
	public:
		// members
		SInt32 hourPackageEvaluated;  // 0
	};
	STATIC_ASSERT(sizeof(MiddleLowProcessData) == 0x4);


	struct CachedValueData
	{
		bool   dirty;  // 0
		UInt8  pad1;   // 1
		UInt16 pad2;   // 2
		float  value;  // 4
	};
	STATIC_ASSERT(sizeof(CachedValueData) == 0x8);


	struct CachedValues
	{
		enum class Flags : UInt32
		{
			kNone = 0,
			kRadius = 1 << 0,
			kWidth = 1 << 1,
			kLength = 1 << 2,
			kDPS = 1 << 3,
			kMedicineEffectivenessMult = 1 << 4,
			kEyeLevel = 1 << 9,
			kConditionPreventsRun = 1 << 10,
			kForwardLength = 1 << 11,
			kActorIsGhost = 1 << 20,
			kHealthDamaged = 1 << 21,
			kMagickaPointsDamaged = 1 << 22,
			kStaminaDamaged = 1 << 23,
			kOwnerIsNPC = 1 << 25,
			kOwnerIsUndead = 1 << 26,
			kOwnerIsInCombatantFaction = 1 << 27
		};


		enum class BooleanValue : UInt32
		{
			kNone = 0,
			kConditionPreventsRun = 1 << 0,
			kOwnerIsNPC = 1 << 1,
			kOwnerIsUndead = 1 << 2,
			kOwnerIsInCombatantFaction = 1 << 3
		};


		float					  cachedRadius;				 // 00
		float					  cachedWidth;				 // 04
		float					  cachedLength;				 // 08
		float					  cachedForwardLength;		 // 0C
		float					  cachedDPS;				 // 10
		float					  cachedEyeLevel;			 // 14
		float					  cachedWalkSpeed;			 // 18
		float					  cachedRunSpeed;			 // 1C
		float					  cachedJogSpeed;			 // 20
		float					  cachedFastWalkSpeed;		 // 24
		BooleanValue			  booleanValues;			 // 28
		Flags					  flags;					 // 2C
		BSTArray<CachedValueData> actorValueCache;			 // 30
		BSTArray<CachedValueData> permanentActorValueCache;	 // 48
	};
	STATIC_ASSERT(sizeof(CachedValues) == 0x60);


	struct ObjectstoAcquire
	{
		UInt64 unk00;  // 00
		UInt64 unk08;  // 08
		UInt64 unk10;  // 10
		UInt64 unk18;  // 18
		UInt64 unk20;  // 20
	};
	STATIC_ASSERT(sizeof(ObjectstoAcquire) == 0x28);


	class AIProcess
	{
	public:
		struct Hands
		{
			enum Hand : UInt32
			{
				kLeft,
				kRight,
				kTotal
			};
		};
		using Hand = Hands::Hand;


		struct Data0B8
		{
			void*	 unk00;	 // 00
			Data0B8* unk08;	 // 08
			void*	 unk10;	 // 10
			void*	 unk18;	 // 18
			UInt64	 unk20;	 // 20
			void*	 unk28;	 // 28
			UInt32	 unk30;	 // 30
			UInt32	 pad34;	 // 34
		};
		STATIC_ASSERT(sizeof(Data0B8) == 0x38);


		float					GetCachedHeight() const;
		bhkCharacterController* GetCharController();
		TESForm*				GetEquippedLeftHand();
		TESForm*				GetEquippedRightHand();
		bool					InHighProcess() const;
		bool					InMiddleHighProcess() const;
		bool					InMiddleLowProcess() const;
		bool					InLowProcess() const;
		bool					IsArrested() const;
		bool					IsGhost() const;
		void					SetArrested(bool a_arrested);
		void					SetCachedHeight(float a_height);
		void					Set3DUpdateFlag(RESET_3D_FLAGS a_flags);
		void					Update3DModel(Actor* a_actor);


		// members
		MiddleLowProcessData*			middleLow;						// 000
		MiddleHighProcessData*			middleHigh;						// 008
		HighProcessData*				high;							// 010
		ActorPackage					currentPackage;					// 018
		float							unk048;							// 048
		UInt32							unk04C;							// 04C
		CachedValues*					cachedValues;					// 050
		SInt32							numberItemsActivate;			// 058
		UInt32							pad05C;							// 05C
		BSSimpleList<ObjectstoAcquire*> objects;						// 060
		BSSimpleList<TESObjectREFR*>	genericLocations;				// 070
		ObjectstoAcquire*				acquireObject;					// 080
		ObjectstoAcquire*				savedAcquireObject;				// 088
		float							essentialDownTimer;				// 090
		float							deathTime;						// 094
		float							trackedDamage;					// 098
		UInt32							pad09C;							// 09C
		BSTArray<TESForm*>				forms;							// 0A0
		Data0B8							unk0B8;							// 0B8
		TESForm*						equippedObjects[Hand::kTotal];	// 0F0
		UInt64							unk100;							// 100
		UInt64							unk108;							// 108
		UInt32							unk110;							// 110
		RefHandle						target;							// 114
		UInt64							unk118;							// 118
		UInt64							unk120;							// 120
		UInt64							unk128;							// 128
		UInt32							unk130;							// 130
		UInt16							unk134;							// 134
		UInt8							lowProcessFlags;				// 136
		PROCESS_TYPE					processLevel;					// 137
		bool							skippedTimeStampForPathing;		// 138
		bool							ignoringCombat;					// 139
		bool							endAlarmOnActor;				// 13A
		bool							escortingPlayer;				// 13B
		UInt32							pad13C;							// 13C

	protected:
		void Update3DModel_Impl(Actor* a_actor);
	};
	STATIC_ASSERT(sizeof(AIProcess) == 0x140);
}
