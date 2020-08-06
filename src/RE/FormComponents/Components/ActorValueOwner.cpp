#include "RE/FormComponents/Components/ActorValueOwner.h"


namespace RE
{
	float ActorValueOwner::GetClampedActorValue(ActorValue a_akValue) const
	{
		using func_t = decltype(&ActorValueOwner::GetClampedActorValue);
		REL::Relocation<func_t> func{ Offset::ActorValueOwner::GetClampedActorValue };
		return func(this, a_akValue);
	}
}
