#include "RE/ThumbstickEvent.h"


namespace RE
{
	bool ThumbstickEvent::IsLeft(void) const
	{
		return keyMask == InputType::kLeftThumbstick;
	}


	bool ThumbstickEvent::IsRight(void) const
	{
		return keyMask == InputType::kRightThumbstick;
	}
}
