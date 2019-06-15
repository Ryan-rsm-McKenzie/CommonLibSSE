#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ActorValueOwner

#include "RE/ActorValues.h"  // ActorValue


namespace RE
{
	class ActorValueOwner
	{
	public:
		inline static const void* RTTI = RTTI_ActorValueOwner;


		virtual ~ActorValueOwner();													// 00

		// add
		virtual float	GetActorValueCurrent(ActorValue a_akValue);					// 01
		virtual float	GetActorValueMaximum(ActorValue a_akValue);					// 02
		virtual float	GetActorValueBase(ActorValue a_akValue);					// 03
		virtual void	SetActorValueBase(ActorValue a_akValue, float a_value);		// 04 - { return; }
		virtual void	ModActorValueBase(ActorValue a_akValue, float a_value);		// 05 - { return; }
		virtual void	Unk_06(void);												// 06 - { return; }
		virtual void	SetActorValueCurrent(ActorValue a_akValue, float a_value);	// 07
		virtual void	Unk_08(void);												// 08

		float			GetPlayerActorValueCurrent(ActorValue a_akValue);
	};
	STATIC_ASSERT(sizeof(ActorValueOwner) == 0x8);
}
