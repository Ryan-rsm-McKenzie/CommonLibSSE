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
		typedef InputManager* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::InputEventDispatcher::GetSingleton));
		return _GetSingleton();
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
