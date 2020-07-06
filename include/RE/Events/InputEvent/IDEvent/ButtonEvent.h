#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/Events/InputEvent/IDEvent/IDEvent.h"
#include "RE/Events/InputEvent/InputEvent.h"


namespace RE
{
	class ButtonEvent : public IDEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_ButtonEvent;


		virtual ~ButtonEvent();	 // 00

		constexpr float Value() const noexcept { return value; }
		constexpr float HeldDuration() const noexcept { return heldDownSecs; }
		constexpr bool	IsPressed() const noexcept { return Value() > 0.0F; }
		constexpr bool	IsRepeating() const noexcept { return HeldDuration() > 0.0F; }
		constexpr bool	IsDown() const noexcept { return IsPressed() && (HeldDuration() == 0.0F); }
		constexpr bool	IsHeld() const noexcept { return IsPressed() && IsRepeating(); }
		constexpr bool	IsUp() const noexcept { return (Value() == 0.0F) && IsRepeating(); }


		// members
		float value;		 // 28
		float heldDownSecs;	 // 2C
	};
	STATIC_ASSERT(sizeof(ButtonEvent) == 0x30);
}
