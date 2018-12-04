#include "RE/InputMappingManager.h"

#include "skse64/GameInput.h"  // InputManager

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSInputDevice.h"  // BSInputDevice
#include "RE/BSTArray.h"  // BSTArray


namespace RE
{
	InputMappingManager* InputMappingManager::GetSingleton()
	{
		typedef InputMappingManager* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::InputManager::GetSingleton));
		return _GetSingleton();
	}


	UInt8 InputMappingManager::AllowTextInput(bool a_allow)
	{
		typedef UInt8 _AllowTextInput_t(InputMappingManager* a_this, bool a_allow);
		static _AllowTextInput_t* _AllowTextInput = reinterpret_cast<_AllowTextInput_t*>(GetFnAddr(&::InputManager::AllowTextInput));
		return _AllowTextInput(this, a_allow);
	}


	UInt32 InputMappingManager::GetMappedKey(const BSFixedString& a_name, DeviceType a_deviceType, Context a_contextIdx) const
	{
		BSTArray<InputContext::Mapping>* maps = 0;

		switch (a_deviceType) {
		case DeviceType::kDeviceType_Mouse:
			maps = &context[a_contextIdx]->mouseMap;
			break;
		case DeviceType::kDeviceType_Gamepad:
			maps = &context[a_contextIdx]->gamepadMap;
			break;
		case DeviceType::kDeviceType_Keyboard:
			maps = &context[a_contextIdx]->keyboardMap;
			break;
		}

		if (maps) {
			for (auto& mapping : *maps) {
				if (mapping.name == a_name) {
					return mapping.buttonID;
				}
			}
		}

		return kInvalid;
	}


	const BSFixedString& InputMappingManager::GetUserEventName(UInt32 a_buttonID, DeviceType a_deviceType, Context a_contextIdx) const
	{
		BSTArray<InputContext::Mapping>* maps = 0;

		switch (a_deviceType) {
		case DeviceType::kDeviceType_Mouse:
			maps = &context[a_contextIdx]->mouseMap;
			break;
		case DeviceType::kDeviceType_Gamepad:
			maps = &context[a_contextIdx]->gamepadMap;
			break;
		case DeviceType::kDeviceType_Keyboard:
			maps = &context[a_contextIdx]->keyboardMap;
			break;
		}

		static BSFixedString none = "";

		if (maps) {
			for (auto& mapping : *maps) {
				if (mapping.buttonID == a_buttonID) {
					return mapping.name;
				}
			}
		}

		return none;
	}


	bool InputMappingManager::IsLookingControlsEnabled() const
	{
		return (controlState & kControlState_Looking) != 0;
	}


	bool InputMappingManager::IsFlyingControlsEnabled() const
	{
		return (controlState & kControlState_Flying) != 0;
	}


	bool InputMappingManager::IsSneakingControlsEnabled() const
	{
		return (controlState & kControlState_Sneaking) != 0;
	}


	bool InputMappingManager::IsMenuControlsEnabled() const
	{
		return (controlState & kControlState_Menu) != 0;
	}


	bool InputMappingManager::IsMovementControlsEnabled() const
	{
		return (controlState & kControlState_Movement) != 0;
	}
}
