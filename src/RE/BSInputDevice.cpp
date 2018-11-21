#include "RE/BSInputDevice.h"


namespace RE
{
	bool BSInputDevice::IsKeyboard() const
	{
		return type == kInputDevice_Keyboard;
	}


	bool BSInputDevice::IsMouse() const
	{
		return type == kInputDevice_Mouse;
	}


	bool BSInputDevice::IsGamepad() const
	{
		return type == kInputDevice_Gamepad;
	}


	bool BSInputDevice::IsPressed(UInt32 keyCode) const
	{
		Data* data = 0; return (codeMap.GetAt(keyCode, data) && data->timer > 0.0f);
	}
}
