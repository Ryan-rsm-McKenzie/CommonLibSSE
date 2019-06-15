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


		struct StateStruct
		{
			constexpr StateStruct(bool a_state1, bool a_state2, bool a_state3, bool a_state4) :
				state1(a_state1),
				state2(a_state2),
				state3(a_state3),
				state4(a_state4),
				pad4(0)
			{}


			bool	state1 : 1;	// 00
			bool	state2 : 1;	// 01
			bool	state3 : 1;	// 02
			bool	state4 : 1;	// 03
			bool	pad4 : 4;	// 04
		};
		STATIC_ASSERT(sizeof(StateStruct) == 0x1);


		union StatePun
		{
			constexpr StatePun(bool a_state1, bool a_state2, bool a_state3, bool a_state4) :
				s(a_state1, a_state2, a_state3, a_state4)
			{}


			StateStruct			s;
			PrimaryAnimState	primaryAnimState;
			FlyingState			flyingState;
			SecondaryAnimState	secondaryAnimState;
			AttackState			attackState;
		};
		STATIC_ASSERT(sizeof(StatePun) == 0x1);


		struct Flags08
		{
			bool	movingBack : 1;				// 00
			bool	movingForward : 1;			// 01
			bool	movingRight : 1;			// 02
			bool	movingLeft : 1;				// 03
			bool	unk04 : 1;					// 04
			bool	unk05 : 1;					// 05
			bool	walking : 1;				// 06
			bool	running : 1;				// 07
			bool	sprinting : 1;				// 08
			bool	sneaking : 1;				// 09
			bool	swimming : 1;				// 0A
			bool	unk0B : 1;					// 0B
			bool	unk0C : 1;					// 0C
			bool	unk0D : 1;					// 0D
			bool	primaryAnimState1 : 1;		// 0E
			bool	primaryAnimState2 : 1;		// 0F
			bool	primaryAnimState3 : 1;		// 10
			bool	primaryAnimState4 : 1;		// 11
			bool	flyingState1 : 1;			// 12
			bool	flyingState2 : 1;			// 13
			bool	flyingState3 : 1;			// 14
			bool	secondaryAnimState1 : 1;	// 15
			bool	secondaryAnimState2 : 1;	// 16
			bool	secondaryAnimState3 : 1;	// 17
			bool	secondaryAnimState4 : 1;	// 18
			bool	unk19 : 1;					// 19
			bool	unk1A : 1;					// 1A
			bool	unk1B : 1;					// 1B
			bool	attackState1 : 1;			// 1C
			bool	attackState2 : 1;			// 1D
			bool	attackState3 : 1;			// 1E
			bool	attackState4 : 1;			// 1F
		};


		enum class Flag0C : UInt32
		{
			kNone = 0,

			kCanAttack = 1 << 3,

			kLeftHandReadied = 1 << 5,
			kRightHandReadied = 1 << 6,
		};


		virtual ~ActorState();					// 00

		// override (IMovementState)
		virtual void	Unk_01(void) override;	// 01
		virtual void	Unk_02(void) override;	// 02
		virtual void	Unk_03(void) override;	// 03
		virtual void	Unk_04(void) override;	// 04
		virtual void	Unk_05(void) override;	// 05
		virtual void	Unk_06(void) override;	// 06
		virtual void	Unk_07(void) override;	// 07
		virtual void	Unk_08(void) override;	// 08

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
