#include "RE/ActorState.h"


namespace RE
{
	ActorState::SitState ActorState::GetSitState() const
	{
		StatePun statePun(flags08.primaryAnimState1, flags08.primaryAnimState2, flags08.primaryAnimState3, flags08.primaryAnimState4);
		switch (statePun.primaryAnimState) {
		case PrimaryAnimState::kSit1:
		case PrimaryAnimState::kSit2:
			return SitState::kWantsToSit;
		case PrimaryAnimState::kSit3:
			return SitState::kSitting;
		case PrimaryAnimState::kSit4:
			return SitState::kWantsToStand;
		default:
			return SitState::kNotSitting;
		}
	}


	ActorState::SleepState ActorState::GetSleepState() const
	{
		StatePun statePun(flags08.primaryAnimState1, flags08.primaryAnimState2, flags08.primaryAnimState3, flags08.primaryAnimState4);
		switch (statePun.primaryAnimState) {
		case PrimaryAnimState::kSleep5:
		case PrimaryAnimState::kSleep6:
			return SleepState::kWantsToSleep;
		case PrimaryAnimState::kSleep7:
			return SleepState::kSleeping;
		case PrimaryAnimState::kSleep8:
			return SleepState::kWantsToWake;
		default:
			return SleepState::kNotSleeping;
		}
	}


	ActorState::FlyingState ActorState::GetFlyingState() const
	{
		StatePun statePun(flags08.flyingState1, flags08.flyingState2, flags08.flyingState3, 0);
		switch (statePun.flyingState) {
		case FlyingState::kTakingOff:
		case FlyingState::kCruising:
		case FlyingState::kHovering:
		case FlyingState::kLanding:
			return statePun.flyingState;
		default:
			return FlyingState::kNotFlying;
		}
	}


	ActorState::AttackState ActorState::GetAttackState() const
	{
		StatePun statePun(flags08.attackState1, flags08.attackState2, flags08.attackState3, flags08.attackState4);
		return statePun.attackState;
	}


	bool ActorState::IsBleedingOut() const
	{
		StatePun statePun(flags08.secondaryAnimState1, flags08.secondaryAnimState2, flags08.secondaryAnimState3, flags08.secondaryAnimState4);
		switch (statePun.secondaryAnimState) {
		case SecondaryAnimState::kBleedOut7:
		case SecondaryAnimState::kBleedOut8:
			return true;
		default:
			return false;
		}
	}


	bool ActorState::IsWeaponDrawn() const
	{
		return ((flags0C >> 5) & 7) >= 3;
	}


	bool ActorState::IsSneaking() const
	{
		return flags08.sneaking;
	}


	bool ActorState::IsSwimming() const
	{
		return flags08.swimming;
	}


	bool ActorState::IsSprinting() const
	{
		return flags08.sprinting;
	}


	bool ActorState::IsFlying() const
	{
		switch (GetFlyingState()) {
		case FlyingState::kNotFlying:
		case FlyingState::kUnkState:
			return false;
		default:
			return true;
		}
	}


	bool ActorState::IsUnconscious() const
	{
		StatePun statePun(flags08.secondaryAnimState1, flags08.secondaryAnimState2, flags08.secondaryAnimState3, flags08.secondaryAnimState4);
		return statePun.secondaryAnimState == SecondaryAnimState::kUnconscious3;
	}
}
