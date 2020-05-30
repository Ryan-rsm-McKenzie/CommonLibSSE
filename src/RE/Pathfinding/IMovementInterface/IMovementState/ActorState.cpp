#include "RE/ActorState.h"


namespace RE
{
	ATTACK_STATE_ENUM ActorState::GetAttackState() const
	{
		return static_cast<ATTACK_STATE_ENUM>(pun_bits(actorState1.meleeAttackState1, actorState1.meleeAttackState2, actorState1.meleeAttackState3, actorState1.meleeAttackState4));
	}


	FLY_STATE ActorState::GetFlyState() const
	{
		return static_cast<FLY_STATE>(pun_bits(actorState1.flyState1, actorState1.flyState2, actorState1.flyState3));
	}


	KNOCK_STATE_ENUM ActorState::GetKnockState() const
	{
		return static_cast<KNOCK_STATE_ENUM>(pun_bits(actorState1.knockState1, actorState1.knockState2, actorState1.knockState3));
	}


	ACTOR_LIFE_STATE ActorState::GetLifeState() const
	{
		return static_cast<ACTOR_LIFE_STATE>(pun_bits(actorState1.lifeState1, actorState1.lifeState2, actorState1.lifeState3, actorState1.lifeState4));
	}


	SIT_SLEEP_STATE ActorState::GetSitSleepState() const
	{
		return static_cast<SIT_SLEEP_STATE>(pun_bits(actorState1.sitSleepState1, actorState1.sitSleepState2, actorState1.sitSleepState3, actorState1.sitSleepState4));
	}


	WEAPON_STATE ActorState::GetWeaponState() const
	{
		return static_cast<WEAPON_STATE>(pun_bits(actorState2.weaponState1, actorState2.weaponState2, actorState2.weaponState3));
	}


	bool ActorState::IsBleedingOut() const
	{
		switch (GetLifeState()) {
		case ACTOR_LIFE_STATE::kEssentialDown:
		case ACTOR_LIFE_STATE::kBleedout:
			return true;
		default:
			return false;
		}
	}


	bool ActorState::IsFlying() const
	{
		switch (GetFlyState()) {
		case FLY_STATE::kNone:
		case FLY_STATE::kPerching:
			return false;
		default:
			return true;
		}
	}


	bool ActorState::IsSneaking() const
	{
		return actorState1.sneaking;
	}


	bool ActorState::IsSprinting() const
	{
		return actorState1.sprinting;
	}


	bool ActorState::IsSwimming() const
	{
		return actorState1.swimming;
	}


	bool ActorState::IsUnconscious() const
	{
		return GetLifeState() == ACTOR_LIFE_STATE::kUnconcious;
	}


	bool ActorState::IsWeaponDrawn() const
	{
		switch (GetWeaponState()) {
		case WEAPON_STATE::kDrawn:
		case WEAPON_STATE::kWantToSheathe:
		case WEAPON_STATE::kSheathing:
			return true;
		default:
			return false;
		}
	}
}
