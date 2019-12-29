#include "RE/BSInputDevice.h"


namespace RE
{
	bool BSInputDevice::IsKeyboard() const
	{
		return device == InputDevice::kKeyboard;
	}


	bool BSInputDevice::IsMouse() const
	{
		return device == InputDevice::kMouse;
	}


	bool BSInputDevice::IsGamepad() const
	{
		return device == InputDevice::kGamepad;
	}


	bool BSInputDevice::IsPressed(UInt32 a_keyCode) const
	{
		auto it = deviceButtons.find(a_keyCode);
		return (it != deviceButtons.end()) && (it->second->heldDownSecs > 0.0);
	}
}
