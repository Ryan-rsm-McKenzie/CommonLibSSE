#include "RE/ActorValueOwner.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	float ActorValueOwner::GetPlayerActorValueCurrent(ActorValue a_akValue)
	{
		typedef float _GetPlayerActorValueCurrent_t(ActorValueOwner* a_this, ActorValue a_akValue);
		static RelocAddr<_GetPlayerActorValueCurrent_t*> _GetPlayerActorValueCurrent(ACTOR_VALUE_OWNER_GET_PLAYER_ACTOR_VALUE_CURRENT);
		return _GetPlayerActorValueCurrent(this, a_akValue);
	}
}
