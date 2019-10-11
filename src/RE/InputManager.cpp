#include "RE/InputManager.h"

#include "skse64/GameInput.h"  // InputEventDispatcher

#include "RE/BSPCGamepadDeviceDelegate.h"  // BSPCGamepadDeviceDelegate
#include "RE/BSPCGamepadDeviceHandler.h"  // BSPCGamepadDeviceHandler
#include "RE/BSWin32KeyboardDevice.h"  // BSWin32KeyboardDevice
#include "RE/BSWin32MouseDevice.h"  // BSWin32MouseDevice
#include "RE/BSWin32VirtualKeyboardDevice.h"  // BSWin32VirtualKeyboardDevice


namespace RE
{
	InputManager* InputManager::GetSingleton()
	{
		using func_t = function_type_t<decltype(&InputManager::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(&::InputEventDispatcher::GetSingleton);
		return func();
	}


	BSPCGamepadDeviceDelegate* InputManager::GetGamepad()
	{
		auto handler = GetGamepadHandler();
		return handler ? handler->gamepad : 0;
	}


	BSPCGamepadDeviceHandler* InputManager::GetGamepadHandler()
	{
		return static_cast<BSPCGamepadDeviceHandler*>(devices[Device::kGamepadHandler]);
	}


	BSWin32KeyboardDevice* InputManager::GetKeyboard()
	{
		return static_cast<BSWin32KeyboardDevice*>(devices[Device::kKeyboard]);
	}


	BSWin32MouseDevice* InputManager::GetMouse()
	{
		return static_cast<BSWin32MouseDevice*>(devices[Device::kMouse]);
	}


	BSWin32VirtualKeyboardDevice* InputManager::GetVirtualKeyboard()
	{
		return static_cast<BSWin32VirtualKeyboardDevice*>(devices[Device::kVirtualKeyboard]);
	}


	bool InputManager::IsGamepadConnected()
	{
		auto handler = GetGamepadHandler();
		return handler && handler->gamepad;
	}


	bool InputManager::IsGamepadEnabled()
	{
		auto handler = GetGamepadHandler();
		return handler && handler->gamepad && handler->gamepad->IsEnabled();
	}
}
