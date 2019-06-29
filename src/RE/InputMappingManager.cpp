#include "RE/InputMappingManager.h"

#include "skse64/GameInput.h"  // InputManager

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTArray.h"  // BSTArray


namespace RE
{
	InputMappingManager* InputMappingManager::GetSingleton()
	{
		using func_t = function_type_t<decltype(&InputMappingManager::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(&::InputManager::GetSingleton);
		return func();
	}


	UInt8 InputMappingManager::AllowTextInput(bool a_allow)
	{
		using func_t = function_type_t<decltype(&InputMappingManager::AllowTextInput)>;
		func_t* func = unrestricted_cast<func_t*>(&::InputManager::AllowTextInput);
		return func(this, a_allow);
	}


	UInt32 InputMappingManager::GetMappedKey(const std::string_view& a_name, DeviceType a_deviceType, Context a_contextIdx) const
	{
		BSTArray<InputContext::Mapping>* maps = 0;
		switch (a_deviceType) {
		case DeviceType::kMouse:
			maps = &context[a_contextIdx]->mouseMap;
			break;
		case DeviceType::kGamepad:
			maps = &context[a_contextIdx]->gamepadMap;
			break;
		case DeviceType::kKeyboard:
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
		case DeviceType::kMouse:
			maps = &context[a_contextIdx]->mouseMap;
			break;
		case DeviceType::kGamepad:
			maps = &context[a_contextIdx]->gamepadMap;
			break;
		case DeviceType::kKeyboard:
			maps = &context[a_contextIdx]->keyboardMap;
			break;
		}

		if (maps) {
			for (auto& mapping : *maps) {
				if (mapping.buttonID == a_buttonID) {
					return mapping.name;
				}
			}
		}

		static BSFixedString empty = "";
		return empty;
	}


	bool InputMappingManager::IsLookingControlsEnabled() const
	{
		return (controlState & ControlState::kLooking) != ControlState::kNone;
	}


	bool InputMappingManager::IsFlyingControlsEnabled() const
	{
		return (controlState & ControlState::kFlying) != ControlState::kNone;
	}


	bool InputMappingManager::IsSneakingControlsEnabled() const
	{
		return (controlState & ControlState::kSneaking) != ControlState::kNone;
	}


	bool InputMappingManager::IsMenuControlsEnabled() const
	{
		return (controlState & ControlState::kMenu) != ControlState::kNone;
	}


	bool InputMappingManager::IsMovementControlsEnabled() const
	{
		return (controlState & ControlState::kMovement) != ControlState::kNone;
	}
}
