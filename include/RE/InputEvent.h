#pragma once

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class InputEvent
	{
	public:
		enum class DeviceType : UInt32
		{
			kKeyboard = 0,
			kMouse,
			kGamepad
		};


		enum class EventType : UInt32
		{
			kButton = 0,
			kMouseMove,
			kChar,
			kThumbstick,
			kDeviceConnect,
			kKinect
		};


		virtual ~InputEvent();									// 0

		virtual bool					IsIDEvent() const;		// 1 - { return false; }
		virtual const BSFixedString&	GetControlID() const;	// 2 - { static BSFixedString str(""); return str; }


		DeviceType		deviceType;	// 08
		EventType		eventType;	// 0C
		InputEvent*		next;		// 10
	};
}
