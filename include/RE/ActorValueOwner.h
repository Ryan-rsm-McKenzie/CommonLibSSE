#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ActorValueOwner

#include "RE/ActorValues.h"  // ActorValue


namespace RE
{
	class ActorValueOwner
	{
	public:
		inline static const void* RTTI = RTTI_ActorValueOwner;


		virtual ~ActorValueOwner();																	// 00

		// add
		virtual float	GetActorValueCurrent(ActorValue a_akValue);									// 01 - { return 0.0; }
		virtual float	GetActorValueMaximum(ActorValue a_akValue);									// 02 - { return 0.0; }
		virtual float	GetActorValueBase(ActorValue a_akValue);									// 03 - { return 0.0; }
		virtual void	SetActorValueBase(ActorValue a_akValue, float a_value);						// 04 - { return; }
		virtual void	ModActorValueBase(ActorValue a_akValue, float a_value);						// 05 - { return; }
		virtual void	ModActorValueCurrent(UInt32 a_arg1, ActorValue a_akValue, float a_value);	// 06 - { return; }
		virtual void	SetActorValueCurrent(ActorValue a_akValue, float a_value);					// 07 - { SetActorValueBase(a_akValue, a_value); }
		virtual bool	UsePCAVMult() const;														// 08 - { return false; }

		float			GetPlayerActorValueCurrent(ActorValue a_akValue);
	};
	STATIC_ASSERT(sizeof(ActorValueOwner) == 0x8);
}
