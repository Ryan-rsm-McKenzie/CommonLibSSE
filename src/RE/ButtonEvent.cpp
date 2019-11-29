#include "RE/ButtonEvent.h"

#include "RE/Offsets.h"


namespace RE
{
	bool ButtonEvent::IsPressed() const
	{
		return pressure > 0.0;
	}


	bool ButtonEvent::IsRepeating() const
	{
		return timer > 0.0;
	}


	bool ButtonEvent::IsDown() const
	{
		return (pressure > 0.0) && (timer == 0.0);
	}


	bool ButtonEvent::IsHeld() const
	{
		return (pressure > 0.0) && (timer > 0.0);
	}


	bool ButtonEvent::IsUp() const
	{
		return (pressure == 0.0) && (timer > 0.0);
	}
}
