#include "RE/InputEventDispatcher.h"

#include "skse64/GameInput.h"  // InputEventDispatcher

#include "RE/BSGamepadDevice.h"  // BSGamepadDevice
#include "RE/BSPCGamepadDeviceHandler.h"  // BSPCGamepadDeviceHandler


namespace RE
{
	InputEventDispatcher* InputEventDispatcher::GetSingleton()
	{
		typedef InputEventDispatcher* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::InputEventDispatcher::GetSingleton));
		return _GetSingleton();
	}


	bool InputEventDispatcher::IsGamepadEnabled()
	{
		return gamepadHandler && gamepadHandler->gamepad && gamepadHandler->gamepad->IsEnabled();
	}


	BSGamepadDevice* InputEventDispatcher::GetGamepad()
	{
		return gamepadHandler ? gamepadHandler->gamepad : 0;
	}
}
