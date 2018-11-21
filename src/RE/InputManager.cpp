#include "RE/InputManager.h"

#include "skse64/GameTypes.h"  // BSFixedString, tArray
#include "skse64/GameInput.h"  // InputManager


namespace RE
{
	InputManager* InputManager::GetSingleton()
	{
		typedef InputManager* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::InputManager::GetSingleton));
		return _GetSingleton();
	}


	UInt8 InputManager::AllowTextInput(bool a_allow)
	{
		typedef UInt8 _AllowTextInput_t(InputManager* a_this, bool a_allow);
		static _AllowTextInput_t* _AllowTextInput = reinterpret_cast<_AllowTextInput_t*>(GetFnAddr(&::InputManager::AllowTextInput));
		return _AllowTextInput(this, a_allow);
	}


	UInt32 InputManager::GetMappedKey(const BSFixedString& a_name, InputDevice a_deviceType, Context a_contextIdx) const
	{
		tArray<InputContext::Mapping>* maps = 0;

		switch (a_deviceType) {
		case InputDevice::kInputDevice_Mouse:
			maps = &context[a_contextIdx]->mouseMap;
			break;
		case InputDevice::kInputDevice_Gamepad:
			maps = &context[a_contextIdx]->gamepadMap;
			break;
		case InputDevice::kInputDevice_Keyboard:
			maps = &context[a_contextIdx]->keyboardMap;
			break;
		}

		if (maps) {
			InputContext::Mapping mapping;
			for (int i = 0; i < maps->count; ++i) {
				if (maps->GetNthItem(i, mapping) && mapping.name == a_name) {
					return mapping.buttonID;
				}
			}
		}

		return kInvalid;
	}


	const BSFixedString& InputManager::GetUserEventName(UInt32 a_buttonID, InputDevice a_deviceType, Context a_contextIdx) const
	{
		tArray<InputContext::Mapping>* maps = 0;

		switch (a_deviceType) {
		case InputDevice::kInputDevice_Mouse:
			maps = &context[a_contextIdx]->mouseMap;
			break;
		case InputDevice::kInputDevice_Gamepad:
			maps = &context[a_contextIdx]->gamepadMap;
			break;
		case InputDevice::kInputDevice_Keyboard:
			maps = &context[a_contextIdx]->keyboardMap;
			break;
		}

		static BSFixedString none = "";

		if (maps) {
			static InputContext::Mapping mapping;
			for (int i = 0; i < maps->count; ++i) {
				if (maps->GetNthItem(i, mapping) && mapping.buttonID == a_buttonID) {
					return mapping.name;
				}
			}
		}

		return none;
	}


	bool InputManager::IsLookingControlsEnabled() const
	{
		return (controlState & kControlState_Looking) != 0;
	}


	bool InputManager::IsFlyingControlsEnabled() const
	{
		return (controlState & kControlState_Flying) != 0;
	}


	bool InputManager::IsSneakingControlsEnabled() const
	{
		return (controlState & kControlState_Sneaking) != 0;
	}


	bool InputManager::IsMenuControlsEnabled() const
	{
		return (controlState & kControlState_Menu) != 0;
	}


	bool InputManager::IsMovementControlsEnabled() const
	{
		return (controlState & kControlState_Movement) != 0;
	}
}
