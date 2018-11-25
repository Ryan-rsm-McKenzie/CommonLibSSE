#include "RE/ThumbstickEvent.h"


namespace RE
{
	bool ThumbstickEvent::IsLeft(void) const
	{
		return keyMask == kInputType_LeftThumbstick;
	}


	bool ThumbstickEvent::IsRight(void) const
	{
		return keyMask == kInputType_RightThumbstick;
	}
}
