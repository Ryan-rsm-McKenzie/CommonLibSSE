#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	bool PlayerInputHandler::IsInputEventHandlingEnabled() const
	{
		return inputEventHandlingEnabled;
	}

	void PlayerInputHandler::SetInputEventHandlingEnabled(bool a_enabled)
	{
		inputEventHandlingEnabled = a_enabled;
	}
}
