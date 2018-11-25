#include "RE/BSInputDevice.h"

#include "RE/InputEvent.h"  //
namespace RE
{
	bool BSInputDevice::IsKeyboard() const
	{
		return type == DeviceType::kDeviceType_Keyboard;
	}


	bool BSInputDevice::IsMouse() const
	{
		return type == DeviceType::kDeviceType_Mouse;
	}


	bool BSInputDevice::IsGamepad() const
	{
		return type == DeviceType::kDeviceType_Gamepad;
	}


	bool BSInputDevice::IsPressed(UInt32 keyCode) const
	{
		Data* data = 0; return (codeMap.GetAt(keyCode, data) && data->timer > 0.0f);
	}
}
