#include "RE/ActorValueOwner.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	float ActorValueOwner::GetClampedActorValue(ActorValue a_akValue) const
	{
		using func_t = decltype(&ActorValueOwner::GetClampedActorValue);
		REL::Offset<func_t> func(Offset::ActorValueOwner::GetClampedActorValue);
		return func(this, a_akValue);
	}
}
