#include "RE/A/ActorValueOwner.h"

namespace RE
{
	float ActorValueOwner::GetArmorRatingSkillMultiplier(float a_skillLevel) const
	{
		using func_t = decltype(&ActorValueOwner::GetArmorRatingSkillMultiplier);
		REL::Relocation<func_t> func(REL::ID(25858));
		return func(this, a_skillLevel);
	}

	float ActorValueOwner::GetClampedActorValue(ActorValue a_akValue) const
	{
		using func_t = decltype(&ActorValueOwner::GetClampedActorValue);
		REL::Relocation<func_t> func{ Offset::ActorValueOwner::GetClampedActorValue };
		return func(this, a_akValue);
	}
}
