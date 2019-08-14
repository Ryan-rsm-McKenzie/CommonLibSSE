#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ActorValueMeter

#include "RE/ActorValues.h"  // ActorValue
#include "RE/HUDMeter.h"  // HUDMeter


namespace RE
{
	class ActorValueMeter : public HUDMeter
	{
	public:
		inline static const void* RTTI = RTTI_ActorValueMeter;


		virtual ~ActorValueMeter();	// 00

		// override (HUDMeter)
		virtual bool	ProcessMessage(UIMessage* a_message) override;	// 02
		virtual float	GetFillPct() override;							// 05


		// members
		ActorValue	actorValue;	// 48
		UInt32		pad4C;		// 4C
	};
	STATIC_ASSERT(sizeof(ActorValueMeter) == 0x50);
}
