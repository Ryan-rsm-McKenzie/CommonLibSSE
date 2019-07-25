#pragma once

#include "skse64/GameRTTI.h"  // RTTI_InputEvent

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/DeviceTypes.h"  // DeviceType


namespace RE
{
	class InputEvent
	{
	public:
		inline static const void* RTTI = RTTI_InputEvent;


		enum class EventType : UInt32
		{
			kButton = 0,
			kMouseMove,
			kChar,
			kThumbstick,
			kDeviceConnect,
			kKinect
		};


		virtual ~InputEvent();									// 00

		virtual bool					IsIDEvent() const;		// 01 - { return false; }
		virtual const BSFixedString&	GetControlID() const;	// 02 - { static BSFixedString str(""); return str; }


		DeviceType	deviceType;	// 08
		EventType	eventType;	// 0C
		InputEvent*	next;		// 10
	};
	STATIC_ASSERT(sizeof(InputEvent) == 0x18);
}
