#include "RE/InputManager.h"

#include "RE/BSPCGamepadDeviceDelegate.h"
#include "RE/BSPCGamepadDeviceHandler.h"
#include "RE/BSWin32KeyboardDevice.h"
#include "RE/BSWin32MouseDevice.h"
#include "RE/BSWin32VirtualKeyboardDevice.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	InputManager* InputManager::GetSingleton()
	{
		REL::Offset<InputManager**> singleton(Offset::InputManager::Singleton);
		return *singleton;
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
