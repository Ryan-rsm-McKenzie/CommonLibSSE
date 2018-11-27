#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/IDEvent.h"  // IDEvent
#include "RE/InputEvent.h"  // InputEvent


namespace RE
{
	class ButtonEvent : public IDEvent
	{
	public:
		virtual ~ButtonEvent();											// 0

		// override (InputEvent)
		virtual bool					IsIDEvent() const override;		// 1
		virtual const BSFixedString&	GetControlID() const override;	// 2

		bool							IsPressed() const;
		bool							IsRepeating() const;
		bool							IsDown() const;
		bool							IsHeld() const;
		bool							IsUp() const;


		// members
		UInt32	keyMask;	// 20
		UInt32	pad24;		// 24
		float	pressure;	// 28
		float	timer;		// 2C
	};
}
