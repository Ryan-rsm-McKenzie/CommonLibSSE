#include "RE/BSDevices/BSInputDeviceManager.h"

#include "RE/BSDevices/BSIInputDevice/BSInputDevice/BSGamepadDevice/BSPCGamepadDeviceDelegate/BSPCGamepadDeviceDelegate.h"
#include "RE/BSDevices/BSIInputDevice/BSInputDevice/BSKeyboardDevice/BSVirtualKeyboardDevice/BSWin32VirtualKeyboardDevice.h"
#include "RE/BSDevices/BSIInputDevice/BSInputDevice/BSKeyboardDevice/BSWin32KeyboardDevice.h"
#include "RE/BSDevices/BSIInputDevice/BSInputDevice/BSMouseDevice/BSWin32MouseDevice.h"
#include "RE/BSDevices/BSIInputDevice/BSPCGamepadDeviceHandler.h"


namespace RE
{
	BSInputDeviceManager* BSInputDeviceManager::GetSingleton()
	{
		REL::Relocation<BSInputDeviceManager**> singleton{ Offset::BSInputDeviceManager::Singleton };
		return *singleton;
	}


	BSPCGamepadDeviceDelegate* BSInputDeviceManager::GetGamepad()
	{
		auto handler = GetGamepadHandler();
		return handler ? handler->currentPCGamePadDelegate : nullptr;
	}


	BSPCGamepadDeviceHandler* BSInputDeviceManager::GetGamepadHandler()
	{
		return static_cast<BSPCGamepadDeviceHandler*>(devices[to_underlying(INPUT_DEVICE::kGamepad)]);
	}


	BSWin32KeyboardDevice* BSInputDeviceManager::GetKeyboard()
	{
		return static_cast<BSWin32KeyboardDevice*>(devices[to_underlying(INPUT_DEVICE::kKeyboard)]);
	}


	BSWin32MouseDevice* BSInputDeviceManager::GetMouse()
	{
		return static_cast<BSWin32MouseDevice*>(devices[to_underlying(INPUT_DEVICE::kMouse)]);
	}


	BSWin32VirtualKeyboardDevice* BSInputDeviceManager::GetVirtualKeyboard()
	{
		return static_cast<BSWin32VirtualKeyboardDevice*>(devices[to_underlying(INPUT_DEVICE::kVirtualKeyboard)]);
	}


	bool BSInputDeviceManager::IsGamepadConnected()
	{
		auto handler = GetGamepadHandler();
		return handler && handler->currentPCGamePadDelegate;
	}


	bool BSInputDeviceManager::IsGamepadEnabled()
	{
		auto handler = GetGamepadHandler();
		return handler && handler->currentPCGamePadDelegate && handler->currentPCGamePadDelegate->IsEnabled();
	}
}
