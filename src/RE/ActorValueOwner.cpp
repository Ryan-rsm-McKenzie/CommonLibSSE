#include "RE/ActorValueOwner.h"

#include "RE/Offsets.h"


namespace RE
{
	float ActorValueOwner::GetPlayerActorValueCurrent(ActorValue a_akValue)
	{
		using func_t = function_type_t<decltype(&ActorValueOwner::GetPlayerActorValueCurrent)>;
		RelocUnrestricted<func_t*> func(Offset::ActorValueOwner::GetPlayerActorValueCurrent);
		return func(this, a_akValue);
	}
}
