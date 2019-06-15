#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ButtonEvent

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/IDEvent.h"  // IDEvent
#include "RE/InputEvent.h"  // InputEvent


namespace RE
{
	class ButtonEvent : public IDEvent
	{
	public:
		inline static const void* RTTI = RTTI_ButtonEvent;


		virtual ~ButtonEvent();	// 00

		bool	IsPressed() const;
		bool	IsRepeating() const;
		bool	IsDown() const;
		bool	IsHeld() const;
		bool	IsUp() const;


		// members
		float	pressure;	// 28
		float	timer;		// 2C
	};
	STATIC_ASSERT(sizeof(ButtonEvent) == 0x30);
}
