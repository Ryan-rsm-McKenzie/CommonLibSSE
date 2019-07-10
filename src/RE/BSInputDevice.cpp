#include "RE/BSInputDevice.h"


namespace RE
{
	bool BSInputDevice::IsKeyboard() const
	{
		return deviceType == DeviceType::kKeyboard;
	}


	bool BSInputDevice::IsMouse() const
	{
		return deviceType == DeviceType::kMouse;
	}


	bool BSInputDevice::IsGamepad() const
	{
		return deviceType == DeviceType::kGamepad;
	}


	bool BSInputDevice::IsPressed(UInt32 keyCode) const
	{
		Data* data = 0;
		return (codeMap.GetAt(keyCode, data) && data->timer > 0.0f);
	}
}
