#include "RE/ActorState.h"


namespace RE
{
	auto ActorState::GetSitState() const
		-> SitState
	{
		auto primaryAnimState = static_cast<PrimaryAnimState>(pun_bits(flags08.primaryAnimState1, flags08.primaryAnimState2, flags08.primaryAnimState3, flags08.primaryAnimState4));
		switch (primaryAnimState) {
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


	auto ActorState::GetSleepState() const
		-> SleepState
	{
		auto primaryAnimState = static_cast<PrimaryAnimState>(pun_bits(flags08.primaryAnimState1, flags08.primaryAnimState2, flags08.primaryAnimState3, flags08.primaryAnimState4));
		switch (primaryAnimState) {
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


	auto ActorState::GetFlyingState() const
		-> FlyingState
	{
		auto flyingState = static_cast<FlyingState>(pun_bits(flags08.flyingState1, flags08.flyingState2, flags08.flyingState3));
		switch (flyingState) {
		case FlyingState::kTakingOff:
		case FlyingState::kCruising:
		case FlyingState::kHovering:
		case FlyingState::kLanding:
			return flyingState;
		default:
			return FlyingState::kNotFlying;
		}
	}


	auto ActorState::GetAttackState() const
		-> AttackState
	{
		return static_cast<AttackState>(pun_bits(flags08.attackState1, flags08.attackState2, flags08.attackState3, flags08.attackState4));
	}


	bool ActorState::IsBleedingOut() const
	{
		auto secondaryAnimState = static_cast<SecondaryAnimState>(pun_bits(flags08.secondaryAnimState1, flags08.secondaryAnimState2, flags08.secondaryAnimState3, flags08.secondaryAnimState4));
		switch (secondaryAnimState) {
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
		auto secondaryAnimState = static_cast<SecondaryAnimState>(pun_bits(flags08.secondaryAnimState1, flags08.secondaryAnimState2, flags08.secondaryAnimState3, flags08.secondaryAnimState4));
		return secondaryAnimState == SecondaryAnimState::kUnconscious3;
	}
}
