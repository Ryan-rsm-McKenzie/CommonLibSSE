#pragma once

#include "RE/BSFixedString.h"
#include "RE/IDEvent.h"
#include "RE/InputEvent.h"


namespace RE
{
	class ButtonEvent : public IDEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_ButtonEvent;


		virtual ~ButtonEvent();	 // 00

		bool IsPressed() const;
		bool IsRepeating() const;
		bool IsDown() const;
		bool IsHeld() const;
		bool IsUp() const;


		// members
		float value;		 // 28
		float heldDownSecs;	 // 2C
	};
	STATIC_ASSERT(sizeof(ButtonEvent) == 0x30);
}
