#include "RE/ButtonEvent.h"


namespace RE
{
	bool ButtonEvent::IsPressed() const
	{
		return pressure > 0;
	}


	bool ButtonEvent::IsDown() const
	{
		return (pressure > 0) && (timer == 0.0f);
	}


	bool ButtonEvent::IsUp() const
	{
		return (pressure == 0) && (timer > 0.0f);
	}
}
