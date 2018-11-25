#pragma once

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class InputEvent
	{
	public:
		enum DeviceType : UInt32
		{
			kDeviceType_Keyboard = 0,
			kDeviceType_Mouse,
			kDeviceType_Gamepad
		};


		enum EventType : UInt32
		{
			kEventType_Button = 0,
			kEventType_MouseMove,
			kEventType_Char,
			kEventType_Thumbstick,
			kEventType_DeviceConnect,
			kEventType_Kinect
		};


		virtual ~InputEvent();									// 0

		virtual bool					IsIDEvent() const;		// 1 - { return false; }
		virtual const BSFixedString&	GetControlID() const;	// 2 - { static BSFixedString str(""); return str; }


		DeviceType		deviceType;	// 08
		EventType		eventType;	// 0C
		InputEvent*		next;		// 10
	};
}
