#include "RE/T/ThumbstickEvent.h"

namespace RE
{
	bool ThumbstickEvent::IsLeft() const
	{
		return idCode == InputType::kLeftThumbstick;
	}

	bool ThumbstickEvent::IsRight() const
	{
		return idCode == InputType::kRightThumbstick;
	}
}
