#include "RE/BSDevices/ControlMap.h"

#include "RE/Events/UserEventEnabled.h"


namespace RE
{
	ControlMap* ControlMap::GetSingleton()
	{
		REL::Offset<ControlMap**> singleton(Offset::ControlMap::Singleton);
		return *singleton;
	}


	SInt8 ControlMap::AllowTextInput(bool a_allow)
	{
		if (a_allow) {
			if (textEntryCount != -1) {
				++textEntryCount;
			}
		} else {
			if (textEntryCount != 0) {
				--textEntryCount;
			}
		}

		return textEntryCount;
	}


	UInt32 ControlMap::GetMappedKey(const std::string_view& a_eventID, INPUT_DEVICE a_device, InputContextID a_context) const
	{
		assert(a_device < INPUT_DEVICE::kTotal);
		assert(a_context < InputContextID::kTotal);

		auto mappings =
			controlMap[a_context] ?
				std::addressof(controlMap[a_context]->deviceMappings[a_device]) :
				nullptr;

		if (mappings) {
			BSFixedString eventID = a_eventID;
			for (auto& mapping : *mappings) {
				if (mapping.eventID == eventID) {
					return mapping.inputKey;
				}
			}
		}

		return kInvalid;
	}


	std::string_view ControlMap::GetUserEventName(UInt32 a_buttonID, INPUT_DEVICE a_device, InputContextID a_context) const
	{
		assert(a_device < INPUT_DEVICE::kTotal);
		assert(a_context < InputContextID::kTotal);

		auto mappings =
			controlMap[a_context] ?
				std::addressof(controlMap[a_context]->deviceMappings[a_device]) :
				nullptr;

		if (mappings) {
			UserEventMapping tmp{};
			tmp.inputKey = a_buttonID;
			auto range = std::equal_range(
				mappings->begin(),
				mappings->end(),
				tmp,
				[](auto&& a_lhs, auto&& a_rhs) {
					return a_lhs.inputKey < a_rhs.inputKey;
				});

			return std::distance(range.first, range.second) == 1 ? range.first->eventID : "";
		} else {
			return "";
		}
	}


	void ControlMap::ToggleControls(UEFlag a_flags, bool a_enable)
	{
		auto oldState = enabledControls;

		if (a_enable) {
			enabledControls |= a_flags;
			if (unk11C != UEFlag::kInvalid) {
				unk11C |= a_flags;
			}
		} else {
			enabledControls &= ~a_flags;
			if (unk11C != UEFlag::kInvalid) {
				unk11C &= ~a_flags;
			}
		}

		UserEventEnabled event(oldState, enabledControls);
		SendEvent(&event);
	}
}
