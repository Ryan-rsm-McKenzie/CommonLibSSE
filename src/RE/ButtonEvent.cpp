#include "RE/ButtonEvent.h"

#include "RE/Offsets.h"


namespace RE
{
	bool ButtonEvent::IsPressed() const
	{
		return value > 0.0;
	}


	bool ButtonEvent::IsRepeating() const
	{
		return heldDownSecs > 0.0;
	}


	bool ButtonEvent::IsDown() const
	{
		return (value > 0.0) && (heldDownSecs == 0.0);
	}


	bool ButtonEvent::IsHeld() const
	{
		return (value > 0.0) && (heldDownSecs > 0.0);
	}


	bool ButtonEvent::IsUp() const
	{
		return (value == 0.0) && (heldDownSecs > 0.0);
	}
}
