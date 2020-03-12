#pragma once

#include "RE/IMovementState.h"


namespace RE
{
	enum class ACTOR_LIFE_STATE : UInt32
	{
		kAlive = 0,
		kDying = 1,
		kDead = 2,
		kUnconcious = 3,
		kReanimate = 4,
		kRecycle = 5,
		kRestrained = 6,
		kEssentialDown = 7,
		kBleedout = 8
	};


	enum class ATTACK_STATE_ENUM : UInt32
	{
		kNone = 0,
		kDraw = 1,
		kSwing = 2,
		kHit = 3,
		kNextAttack = 4,
		kFollowThrough = 5,
		kBash = 6,
		kBowDraw = 8,
		kBowAttached = 9,
		kBowDrawn = 10,
		kBowReleasing = 11,
		kBowReleased = 12,
		kBowNextAttack = 13,
		kBowFollowThrough = 14,
		kFire = 15,
		kFiring = 16,
		kFired = 17
	};


	enum class FLY_STATE : UInt32
	{
		kNone = 0,
		kTakeOff = 1,
		kCruising = 2,
		kHovering = 3,
		kLanding = 4,
		kPerching = 5,
		kAction = 6
	};


	enum class KNOCK_STATE_ENUM : UInt32
	{
		kNormal = 0,
		kExplode = 1,
		kExplodeLeadIn = 2,
		kOut = 3,
		kOutLeadIn = 4,
		kQueued = 5,
		kGetUp = 6,
		kDown = 7,
		kWaitForTaskQueue = 8
	};


	enum class SIT_SLEEP_STATE : UInt32
	{
		kNormal = 0,
		kWantToSit = 1,
		kWaitingForSitAnim = 2,

		kIsSitting = 3,
		kRidingMount = kIsSitting,

		kWantToStand = 4,

		kWantToSleep = 5,
		kWaitingForSleepAnim = 6,
		kIsSleeping = 7,
		kWantToWake = 8
	};


	enum class WEAPON_STATE : UInt32
	{
		kSheathed = 0,
		kWantToDraw = 1,
		kDrawing = 2,
		kDrawn = 3,
		kWantToSheathe = 4,
		kSheathing = 5
	};


	class ActorState : public IMovementState
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActorState;


		struct ActorState1
		{
			bool movingBack : 1;		 // 0 - 0
			bool movingForward : 1;		 // 0 - 1
			bool movingRight : 1;		 // 0 - 2
			bool movingLeft : 1;		 // 0 - 3
			bool unk0_4 : 1;			 // 0 - 4
			bool unk0_5 : 1;			 // 0 - 5
			bool walking : 1;			 // 0 - 6
			bool running : 1;			 // 0 - 7
			bool sprinting : 1;			 // 1 - 0
			bool sneaking : 1;			 // 1 - 1
			bool swimming : 1;			 // 1 - 2
			bool unk1_3 : 1;			 // 1 - 3
			bool unk1_4 : 1;			 // 1 - 4
			bool unk1_5 : 1;			 // 1 - 5
			bool sitSleepState1 : 1;	 // 1 - 6
			bool sitSleepState2 : 1;	 // 1 - 7
			bool sitSleepState3 : 1;	 // 2 - 0
			bool sitSleepState4 : 1;	 // 2 - 1
			bool flyState1 : 1;			 // 2 - 2
			bool flyState2 : 1;			 // 2 - 3
			bool flyState3 : 1;			 // 2 - 4
			bool lifeState1 : 1;		 // 2 - 5
			bool lifeState2 : 1;		 // 2 - 6
			bool lifeState3 : 1;		 // 2 - 7
			bool lifeState4 : 1;		 // 3 - 0
			bool knockState1 : 1;		 // 3 - 1
			bool knockState2 : 1;		 // 3 - 2
			bool knockState3 : 1;		 // 3 - 3
			bool meleeAttackState1 : 1;	 // 3 - 4
			bool meleeAttackState2 : 1;	 // 3 - 5
			bool meleeAttackState3 : 1;	 // 3 - 6
			bool meleeAttackState4 : 1;	 // 3 - 7
		};
		STATIC_ASSERT(sizeof(ActorState1) == 0x4);


		struct ActorState2
		{
			bool talkingToPlayer : 1;  // 0 - 0
			bool forceRun : 1;		   // 0 - 1
			bool forceSneak : 1;	   // 0 - 2
			bool headTracking : 1;	   // 0 - 3
			bool reanimating : 1;	   // 0 - 4
			bool weaponState1 : 1;	   // 0 - 5
			bool weaponState2 : 1;	   // 0 - 6
			bool weaponState3 : 1;	   // 0 - 7
			bool wantBlocking : 1;	   // 1 - 0
			bool flightBlocked : 1;	   // 1 - 1
			bool recoil1 : 1;		   // 1 - 2
			bool recoil2 : 1;		   // 1 - 3
			bool allowFlying : 1;	   // 1 - 4
			bool staggered : 1;		   // 1 - 5
			bool unk1_6 : 1;		   // 1 - 6
			bool unk1_7 : 1;		   // 1 - 7
			bool unk2_0 : 1;		   // 2 - 0
			bool unk2_1 : 1;		   // 2 - 1
			bool unk2_2 : 1;		   // 2 - 2
			bool unk2_3 : 1;		   // 2 - 3
			bool unk2_4 : 1;		   // 2 - 4
			bool unk2_5 : 1;		   // 2 - 5
			bool unk2_6 : 1;		   // 2 - 6
			bool unk2_7 : 1;		   // 2 - 7
			bool pad3_0 : 1;		   // 3 - 0
			bool pad3_1 : 1;		   // 3 - 1
			bool pad3_2 : 1;		   // 3 - 2
			bool pad3_3 : 1;		   // 3 - 3
			bool pad3_4 : 1;		   // 3 - 4
			bool pad3_5 : 1;		   // 3 - 5
			bool pad3_6 : 1;		   // 3 - 6
			bool pad3_7 : 1;		   // 3 - 7
		};
		STATIC_ASSERT(sizeof(ActorState2) == 0x4);


		virtual ~ActorState();	// 00

		// override (IMovementState)
		virtual void Unk_01(void) override;	 // 01 - { return 0; }
		virtual void Unk_02(void) override;	 // 02 - { return; }
		virtual void Unk_03(void) override;	 // 03 - { return; }
		virtual void Unk_04(void) override;	 // 04 - { return; }
		virtual void Unk_05(void) override;	 // 05 - { return 0.0; }
		virtual void Unk_06(void) override;	 // 06 - { return 0.0; }
		virtual void Unk_07(void) override;	 // 07 - { return; }
		virtual void Unk_08(void) override;	 // 08 - { return 0; }

		// add
		virtual void Unk_14(void);	// 14
		virtual void Unk_15(void);	// 15

		ATTACK_STATE_ENUM GetAttackState() const;
		FLY_STATE		  GetFlyState() const;
		KNOCK_STATE_ENUM  GetKnockState() const;
		ACTOR_LIFE_STATE  GetLifeState() const;
		SIT_SLEEP_STATE	  GetSitSleepState() const;
		WEAPON_STATE	  GetWeaponState() const;
		bool			  IsBleedingOut() const;
		bool			  IsFlying() const;
		bool			  IsSneaking() const;
		bool			  IsSprinting() const;
		bool			  IsSwimming() const;
		bool			  IsUnconscious() const;
		bool			  IsWeaponDrawn() const;


		// members
		ActorState1 actorState1;  // 08
		ActorState2 actorState2;  // 0C
	};
	STATIC_ASSERT(sizeof(ActorState) == 0x10);
}
