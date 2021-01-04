#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSInputDevice.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/I/InputDevices.h"
#include "RE/P/PCGamepadType.h"
#include "RE/U/UserEvents.h"

namespace RE
{
	class UserEventEnabled;

	class ControlMap :
		public BSTSingletonSDM<ControlMap>,		 // 00
		public BSTEventSource<UserEventEnabled>	 // 08
	{
	public:
		using InputContextID = UserEvents::INPUT_CONTEXT_ID;
		using UEFlag = UserEvents::USER_EVENT_FLAG;

		enum : std::uint32_t
		{
			kInvalid = static_cast<std::uint8_t>(-1)
		};

		struct UserEventMapping
		{
		public:
			// members
			BSFixedString							eventID;			 // 00
			std::uint16_t							inputKey;			 // 08
			std::uint16_t							modifier;			 // 08
			std::int8_t								indexInContext;		 // 0C
			bool									remappable;			 // 0D
			bool									linked;				 // 0E
			stl::enumeration<UEFlag, std::uint32_t> userEventGroupFlag;	 // 10
			std::uint32_t							pad14;				 // 14
		};
		static_assert(sizeof(UserEventMapping) == 0x18);

		struct InputContext
		{
		public:
			// members
			BSTArray<UserEventMapping> deviceMappings[INPUT_DEVICES::kTotal];  // 00
		};
		static_assert(sizeof(InputContext) == 0x60);

		struct LinkedMapping
		{
		public:
			// members
			BSFixedString  linkedMappingName;	  // 00
			InputContextID linkedMappingContext;  // 08
			INPUT_DEVICE   device;				  // 0C
			InputContextID linkFromContext;		  // 10
			std::uint32_t  pad14;				  // 14
			BSFixedString  linkFromName;		  // 18
		};
		static_assert(sizeof(LinkedMapping) == 0x20);

		static ControlMap* GetSingleton();

		std::int8_t		 AllowTextInput(bool a_allow);
		constexpr bool	 AreControlsEnabled(UEFlag a_flags) const noexcept { return enabledControls.all(a_flags); }
		std::uint32_t	 GetMappedKey(std::string_view a_eventID, INPUT_DEVICE a_device, InputContextID a_context = InputContextID::kGameplay) const;
		std::string_view GetUserEventName(std::uint32_t a_buttonID, INPUT_DEVICE a_device, InputContextID a_context = InputContextID::kGameplay) const;
		constexpr bool	 IsActivateControlsEnabled() const noexcept { return enabledControls.all(UEFlag::kActivate); }
		constexpr bool	 IsConsoleControlsEnabled() const noexcept { return enabledControls.all(UEFlag::kConsole); }
		constexpr bool	 IsFightingControlsEnabled() const noexcept { return enabledControls.all(UEFlag::kFighting); }
		constexpr bool	 IsLookingControlsEnabled() const noexcept { return enabledControls.all(UEFlag::kLooking); }
		constexpr bool	 IsMenuControlsEnabled() const noexcept { return enabledControls.all(UEFlag::kMenu); }
		constexpr bool	 IsMainFourControlsEnabled() const noexcept { return enabledControls.all(UEFlag::kMainFour); }
		constexpr bool	 IsMovementControlsEnabled() const noexcept { return enabledControls.all(UEFlag::kMovement); }
		constexpr bool	 IsPOVSwitchControlsEnabled() const noexcept { return enabledControls.all(UEFlag::kPOVSwitch); }
		constexpr bool	 IsSneakingControlsEnabled() const noexcept { return enabledControls.all(UEFlag::kSneaking); }
		constexpr bool	 IsVATSControlsEnabled() const noexcept { return enabledControls.all(UEFlag::kVATS); }
		constexpr bool	 IsWheelZoomControlsEnabled() const noexcept { return enabledControls.all(UEFlag::kWheelZoom); }
		void			 ToggleControls(UEFlag a_flags, bool a_enable);

		// members
		InputContext*									 controlMap[InputContextID::kTotal];  // 060
		BSTArray<LinkedMapping>							 linkedMappings;					  // 0E8
		BSTArray<InputContextID>						 contextPriorityStack;				  // 100
		stl::enumeration<UEFlag, std::uint32_t>			 enabledControls;					  // 118
		stl::enumeration<UEFlag, std::uint32_t>			 unk11C;							  // 11C
		std::int8_t										 textEntryCount;					  // 120
		bool											 ignoreKeyboardMouse;				  // 121
		bool											 ignoreActivateDisabledEvents;		  // 122
		std::uint8_t									 pad123;							  // 123
		stl::enumeration<PC_GAMEPAD_TYPE, std::uint32_t> gamePadMapType;					  // 124
	};
	static_assert(sizeof(ControlMap) == 0x128);
}
