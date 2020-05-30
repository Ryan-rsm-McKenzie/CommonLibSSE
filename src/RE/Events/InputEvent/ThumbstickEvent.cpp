#include "RE/Events/InputEvent/IDEvent/ThumbstickEvent.h"


namespace RE
{
	bool ThumbstickEvent::IsLeft(void) const
	{
		return idCode == InputType::kLeftThumbstick;
	}


	bool ThumbstickEvent::IsRight(void) const
	{
		return idCode == InputType::kRightThumbstick;
	}
}
