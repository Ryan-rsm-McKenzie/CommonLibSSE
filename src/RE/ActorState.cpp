#include "RE/ActorState.h"


namespace RE
{
	UInt32 ActorState::GetSitState() const
	{
		UInt32 state = (flags04 >> 0x0E) & 0x0F;
		switch (state) {
		case 1:
		case 2:
			return kSitState_WantsToSit;
		case 3:
			return kSitState_Sitting;
		case 4:
			return kSitState_WantsToStand;
		default:
			return kSitState_NotSitting;
		}
	}


	UInt32 ActorState::GetSleepState() const
	{
		UInt32 state = (flags04 >> 0x0E) & 0x0F;
		switch (state) {
		case 5:
		case 6:
			return kSleepState_WantsToSleep;
		case 7:
			return kSleepState_Sleeping;
		case 8:
			return kSleepState_WantsToWake;
		default:
			return kSleepState_NotSleeping;
		}
	}


	UInt32 ActorState::GetFlyingState() const
	{
		return (flags04 >> 0x12) & 0x07;
	}


	bool ActorState::IsBleedingOut() const
	{
		UInt32 state = (flags04 >> 0x15) & 0x0F; return (state == 7 || state == 8);
	}


	bool ActorState::IsWeaponDrawn() const
	{
		return (flags08 >> 5 & 7) >= 3;
	}


	bool ActorState::IsSneaking() const
	{
		return (flags04 & kState_Sneaking) != 0;
	}


	bool ActorState::IsSwimming() const
	{
		return (flags04 & kState_Swimming) != 0;
	}


	bool ActorState::IsSprinting() const
	{
		return (flags04 & kState_Sprinting) != 0;
	}


	bool ActorState::IsFlying() const
	{
		UInt32 flyingState = GetFlyingState(); return (flyingState != 0) && (flyingState != 5);
	}


	bool ActorState::IsUnconscious() const
	{
		return (flags04 & 0x01E00000) == 0x00600000;
	}
}
