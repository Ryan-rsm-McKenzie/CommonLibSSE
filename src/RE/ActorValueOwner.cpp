#include "RE/ActorValueOwner.h"

#include "RE/Offsets.h"


namespace RE
{
	float ActorValueOwner::GetPlayerActorValueCurrent(ActorValue a_akValue)
	{
		return _GetPlayerActorValueCurrent(this, a_akValue);
	}


	RelocAddr<ActorValueOwner::_GetPlayerActorValueCurrent_t*> ActorValueOwner::_GetPlayerActorValueCurrent(ACTOR_VALUE_OWNER_GET_PLAYER_ACTOR_VALUE_CURRENT);
}
