#include "RE/BSInputDeviceManager.h"

#include "RE/BSPCGamepadDeviceDelegate.h"
#include "RE/BSPCGamepadDeviceHandler.h"
#include "RE/BSWin32KeyboardDevice.h"
#include "RE/BSWin32MouseDevice.h"
#include "RE/BSWin32VirtualKeyboardDevice.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSInputDeviceManager* BSInputDeviceManager::GetSingleton()
	{
		REL::Offset<BSInputDeviceManager**> singleton(Offset::BSInputDeviceManager::Singleton);
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
