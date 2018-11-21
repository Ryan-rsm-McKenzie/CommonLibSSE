#pragma once

#include "skse64/GameReferences.h"  // IMovementState


namespace RE
{
	class ActorState : public IMovementState
	{
	public:
		enum State : UInt32
		{
			kState_Running		= 1 << 6,
			kState_Walking		= 1 << 7,
			kState_Sprinting	= 1 << 8,
			kState_Sneaking		= 1 << 9,
			kState_Swimming		= 1 << 10,
			kState_Sit			= (0x0F << 0x0E),
			kState_Flying		= (0x07 << 0x12)
		};


		enum SitState : UInt32
		{
			kSitState_NotSitting	= 0,
			kSitState_WantsToSit	= 2,
			kSitState_Sitting		= 3,
			kSitState_WantsToStand	= 4
		};


		enum SleepState : UInt32
		{
			kSleepState_NotSleeping		= 0,
			kSleepState_WantsToSleep	= 2,
			kSleepState_Sleeping		= 3,
			kSleepState_WantsToWake		= 4
		};


		virtual ~ActorState();

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
		UInt32	flags04;	// 08
		UInt32	flags08;	// 0C
	};
	STATIC_ASSERT(sizeof(ActorState) == 0x10);
}
