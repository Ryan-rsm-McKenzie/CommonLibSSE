#pragma once

#include "RE/ActorValues.h"  // ActorValue


namespace RE
{
	class ActorValueOwner
	{
	public:
		virtual ~ActorValueOwner();													// 00

		virtual float	GetActorValueCurrent(ActorValue a_akValue);					// 01
		virtual float	GetActorValueMaximum(ActorValue a_akValue);					// 02
		virtual float	GetActorValueBase(ActorValue a_akValue);					// 03
		virtual void	SetActorValueBase(ActorValue a_akValue, float value);		// 04 - { return; }
		virtual void	ModActorValueBase(ActorValue a_akValue, float value);		// 05 - { return; }
		virtual void	Unk_06(UInt32 arg0, UInt32 arg1, UInt32 arg2);				// 06 - { return; }
		virtual void	SetActorValueCurrent(ActorValue a_akValue, float value);	// 07
		virtual bool	Unk_08(void);												// 08

		float			GetPlayerActorValueCurrent(ActorValue a_akValue);
	};
	STATIC_ASSERT(sizeof(ActorValueOwner) == 0x8);
}
