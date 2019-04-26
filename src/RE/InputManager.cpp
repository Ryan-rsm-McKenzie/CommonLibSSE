#include "RE/InputManager.h"

#include "skse64/GameInput.h"  // InputEventDispatcher

#include "RE/BSGamepadDevice.h"  // BSGamepadDevice
#include "RE/BSPCGamepadDeviceHandler.h"  // BSPCGamepadDeviceHandler
#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/InputEvent.h"  // InputEvent


namespace RE
{
	InputManager* InputManager::GetSingleton()
	{
		using func_t = function_type_t<decltype(&InputManager::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(&::InputEventDispatcher::GetSingleton);
		return func();
	}


	bool InputManager::IsGamepadConnected()
	{
		return gamepadHandler && gamepadHandler->gamepad;
	}


	bool InputManager::IsGamepadEnabled()
	{
		return gamepadHandler && gamepadHandler->gamepad && gamepadHandler->gamepad->IsEnabled();
	}


	BSGamepadDevice* InputManager::GetGamepad()
	{
		return gamepadHandler ? gamepadHandler->gamepad : 0;
	}
}
