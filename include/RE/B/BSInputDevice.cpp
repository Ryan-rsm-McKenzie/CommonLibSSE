#include "RE/B/BSInputDevice.h"

namespace RE
{
	bool BSInputDevice::IsKeyboard() const
	{
		return device == INPUT_DEVICE::kKeyboard;
	}

	bool BSInputDevice::IsMouse() const
	{
		return device == INPUT_DEVICE::kMouse;
	}

	bool BSInputDevice::IsGamepad() const
	{
		return device == INPUT_DEVICE::kGamepad;
	}

	bool BSInputDevice::IsPressed(std::uint32_t a_keyCode) const
	{
		auto it = deviceButtons.find(a_keyCode);
		return (it != deviceButtons.end()) && (it->second->heldDownSecs > 0.0);
	}
}
