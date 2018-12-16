#pragma once

#include "RE/ActorValues.h"  // ActorValue


namespace RE
{
	class ActorValueOwner
	{
	public:
		virtual ~ActorValueOwner();

		virtual float	GetActorValueCurrent(ActorValue a_akValue);
		virtual float	GetActorValueMaximum(ActorValue a_akValue);
		virtual float	GetActorValueBase(ActorValue a_akValue);
		virtual void	SetActorValueBase(ActorValue a_akValue, float value);
		virtual void	ModActorValueBase(ActorValue a_akValue, float value);
		virtual void	Unk_06(UInt32 arg0, UInt32 arg1, UInt32 arg2);
		virtual void	SetActorValueCurrent(ActorValue a_akValue, float value);
		virtual bool	Unk_08(void);

		float			GetPlayerActorValueCurrent(ActorValue a_akValue);
	};
	STATIC_ASSERT(sizeof(ActorValueOwner) == 0x8);
}
