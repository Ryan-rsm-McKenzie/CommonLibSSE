#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ActorState

#include "RE/IMovementState.h"  // IMovementState


namespace RE
{
	class ActorState : public IMovementState
	{
	public:
		inline static const void* RTTI = RTTI_ActorState;


		enum class PrimaryAnimState : UInt8
		{
			kSit1 = 1,
			kSit2 = 2,
			kSit3 = 3,
			kSit4 = 4,

			kSleep5 = 5,
			kSleep6 = 6,
			kSleep7 = 7,
			kSleep8 = 8
		};


		enum class SitState : UInt8
		{
			kNotSitting = 0,
			kWantsToSit = 2,
			kSitting = 3,
			kWantsToStand = 4
		};


		enum class SleepState : UInt8
		{
			kNotSleeping = 0,
			kWantsToSleep = 2,
			kSleeping = 3,
			kWantsToWake = 4
		};


		enum class FlyingState : UInt8
		{
			kNotFlying = 0,
			kTakingOff = 1,
			kCruising = 2,
			kHovering = 3,
			kLanding = 4,
			kUnkState = 5
		};


		enum class SecondaryAnimState : UInt8
		{
			kUnconscious3 = 3,

			kBleedOut7 = 7,
			kBleedOut8 = 8
		};


		enum class AttackState : UInt8
		{
			kNone = 0,
			kDraw = 1,
			kSwing = 2,
			kHit = 3,
			kNextAttack = 4,
			kFollowThrough = 5,
			kBash = 6,
		};


		struct Flags08
		{
			bool	movingBack : 1;				// 0 - 0
			bool	movingForward : 1;			// 0 - 1
			bool	movingRight : 1;			// 0 - 2
			bool	movingLeft : 1;				// 0 - 3
			bool	unk0_4 : 1;					// 0 - 4
			bool	unk0_5 : 1;					// 0 - 5
			bool	walking : 1;				// 0 - 6
			bool	running : 1;				// 0 - 7
			bool	sprinting : 1;				// 1 - 0
			bool	sneaking : 1;				// 1 - 1
			bool	swimming : 1;				// 1 - 2
			bool	unk1_3 : 1;					// 1 - 3
			bool	unk1_4 : 1;					// 1 - 4
			bool	unk1_5 : 1;					// 1 - 5
			bool	primaryAnimState1 : 1;		// 1 - 6
			bool	primaryAnimState2 : 1;		// 1 - 7
			bool	primaryAnimState3 : 1;		// 2 - 0
			bool	primaryAnimState4 : 1;		// 2 - 1
			bool	flyingState1 : 1;			// 2 - 2
			bool	flyingState2 : 1;			// 2 - 3
			bool	flyingState3 : 1;			// 2 - 4
			bool	secondaryAnimState1 : 1;	// 2 - 5
			bool	secondaryAnimState2 : 1;	// 2 - 6
			bool	secondaryAnimState3 : 1;	// 2 - 7
			bool	secondaryAnimState4 : 1;	// 3 - 0
			bool	unk3_1 : 1;					// 3 - 1
			bool	unk3_2 : 1;					// 3 - 2
			bool	unk3_3 : 1;					// 3 - 3
			bool	attackState1 : 1;			// 3 - 4
			bool	attackState2 : 1;			// 3 - 5
			bool	attackState3 : 1;			// 3 - 6
			bool	attackState4 : 1;			// 3 - 7
		};
		STATIC_ASSERT(sizeof(Flags08) == 0x4);


		enum class Flag0C : UInt32
		{
			kNone = 0,

			kCanAttack = 1 << 3,

			kLeftHandReadied = 1 << 5,
			kRightHandReadied = 1 << 6,
		};


		virtual ~ActorState();					// 00

		// override (IMovementState)
		virtual void	Unk_01(void) override;	// 01 - { return 0; }
		virtual void	Unk_02(void) override;	// 02 - { return; }
		virtual void	Unk_03(void) override;	// 03 - { return; }
		virtual void	Unk_04(void) override;	// 04 - { return; }
		virtual void	Unk_05(void) override;	// 05 - { return 0.0; }
		virtual void	Unk_06(void) override;	// 06 - { return 0.0; }
		virtual void	Unk_07(void) override;	// 07 - { return; }
		virtual void	Unk_08(void) override;	// 08 - { return 0; }

		// add
		virtual void	Unk_14(void);			// 14
		virtual void	Unk_15(void);			// 15

		SitState	GetSitState() const;
		SleepState	GetSleepState() const;
		FlyingState	GetFlyingState() const;
		AttackState	GetAttackState() const;
		bool		IsBleedingOut() const;
		bool		IsWeaponDrawn() const;
		bool		IsSneaking() const;
		bool		IsSwimming() const;
		bool		IsSprinting() const;
		bool		IsFlying() const;
		bool		IsUnconscious() const;


		// members
		Flags08	flags08;	// 08
		UInt32	flags0C;	// 0C
	};
	STATIC_ASSERT(sizeof(ActorState) == 0x10);
}
