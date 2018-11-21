#pragma once

#include "skse64/GameInput.h"  // IDEvent, InputEvent


namespace RE
{
	class ButtonEvent :
		public IDEvent,
		public InputEvent
	{
	public:
		virtual					~ButtonEvent();
		virtual bool			IsIDEvent();
		virtual BSFixedString*	GetControlID();

		bool					IsPressed() const;
		bool					IsDown() const;
		bool					IsUp() const;


		// members
		UInt32			keyMask;	// 20
		UInt32			pad24;		// 24
		float			pressure;	// 28
		float			timer;		// 2C
	};
}
