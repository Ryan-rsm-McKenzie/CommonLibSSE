#pragma once

#include "skse64/GameReferences.h"  // IMovementState


namespace RE
{
	class ActorState : public IMovementState
	{
	public:
		enum class Flag08 : UInt32
		{
			kNone = 0,

			kMovingBack = 1 << 0,
			kMovingForward = 1 << 1,
			kMovingRight = 1 << 2,
			kMovingLeft = 1 << 3,

			kWalking = 1 << 6,
			kRunning = 1 << 7,
			kSprinting = 1 << 8,
			kSneaking = 1 << 9,
			kSwimming = 1 << 10,

			kInAction = 1 << 14,		// Sitting, crafting, sleeping, etc
			kEnteringAction = 1 << 15,	// Stays set while in action
			kExitingAction = 1 << 16,
		};


		enum class Flag0C : UInt32
		{
			kNone = 0,

			kCanAttack = 1 << 3,

			kLeftHandReadied = 1 << 5,
			kRightHandReadied = 1 << 6,
		};


		enum State : UInt32
		{
			kState_Running = 1 << 6,
			kState_Walking = 1 << 7,
			kState_Sprinting = 1 << 8,
			kState_Sneaking = 1 << 9,
			kState_Swimming = 1 << 10,
			kState_Sit = (0x0F << 0x0E),
			kState_Flying = (0x07 << 0x12)
		};


		enum SitState : UInt32
		{
			kSitState_NotSitting = 0,
			kSitState_WantsToSit = 2,
			kSitState_Sitting = 3,
			kSitState_WantsToStand = 4
		};


		enum SleepState : UInt32
		{
			kSleepState_NotSleeping = 0,
			kSleepState_WantsToSleep = 2,
			kSleepState_Sleeping = 3,
			kSleepState_WantsToWake = 4
		};


		virtual ~ActorState();	// 00
		// more

		UInt32	GetSitState() const;
		UInt32	GetSleepState() const;
		UInt32	GetFlyingState() const;
		bool	IsBleedingOut() const;
		bool	IsWeaponDrawn() const;
		bool	IsSneaking() const;
		bool	IsSwimming() const;
		bool	IsSprinting() const;
		bool	IsFlying() const;
		bool	IsUnconscious() const;


		// members
		UInt32	flags08;	// 08
		UInt32	flags0C;	// 0C
	};
	STATIC_ASSERT(sizeof(ActorState) == 0x10);
}
