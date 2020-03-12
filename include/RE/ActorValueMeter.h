#pragma once

#include "RE/ActorValues.h"
#include "RE/HUDMeter.h"


namespace RE
{
	class ActorValueMeter : public HUDMeter
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActorValueMeter;


		virtual ~ActorValueMeter();	 // 00

		// override (HUDMeter)
		virtual bool  ProcessMessage(UIMessage* a_message) override;  // 02
		virtual float GetFillPct() override;						  // 05


		// members
		ActorValue actorValue;	// 48
		UInt32	   pad4C;		// 4C
	};
	STATIC_ASSERT(sizeof(ActorValueMeter) == 0x50);
}
