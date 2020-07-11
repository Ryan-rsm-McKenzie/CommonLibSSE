#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTEvent.h"
#include "RE/BSCore/BSTSingleton.h"
#include "RE/BSDevices/BSIInputDevice/BSInputDevice/BSInputDevice.h"
#include "RE/BSDevices/Enums/InputDevices.h"
#include "RE/BSDevices/Enums/PCGamepadType.h"
#include "RE/BSDevices/UserEvents.h"


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


		enum : UInt32
		{
			kInvalid = static_cast<UInt8>(-1)
		};


		struct UserEventMapping
		{
		public:
			// members
			BSFixedString eventID;			   // 00
			UInt16		  inputKey;			   // 08
			UInt16		  modifier;			   // 08
			SInt8		  indexInContext;	   // 0C
			bool		  remappable;		   // 0D
			bool		  linked;			   // 0E
			UEFlag		  userEventGroupFlag;  // 10
			UInt32		  pad14;			   // 14
		};
		STATIC_ASSERT(sizeof(UserEventMapping) == 0x18);


		struct InputContext
		{
		public:
			// members
			BSTArray<UserEventMapping> deviceMappings[INPUT_DEVICES::kTotal];  // 00
		};
		STATIC_ASSERT(sizeof(InputContext) == 0x60);


		struct LinkedMapping
		{
		public:
			// members
			BSFixedString  linkedMappingName;	  // 00
			InputContextID linkedMappingContext;  // 08
			INPUT_DEVICE   device;				  // 0C
			InputContextID linkFromContext;		  // 10
			UInt32		   pad14;				  // 14
			BSFixedString  linkFromName;		  // 18
		};
		STATIC_ASSERT(sizeof(LinkedMapping) == 0x20);


		static ControlMap* GetSingleton();

		SInt8			 AllowTextInput(bool a_allow);
		constexpr bool	 AreControlsEnabled(UEFlag a_flags) const noexcept { return (enabledControls & a_flags) == a_flags; }
		UInt32			 GetMappedKey(const std::string_view& a_eventID, INPUT_DEVICE a_device, InputContextID a_context = InputContextID::kGameplay) const;
		std::string_view GetUserEventName(UInt32 a_buttonID, INPUT_DEVICE a_device, InputContextID a_context = InputContextID::kGameplay) const;
		constexpr bool	 IsActivateControlsEnabled() const noexcept { return (enabledControls & UEFlag::kActivate) != UEFlag::kNone; }
		constexpr bool	 IsConsoleControlsEnabled() const noexcept { return (enabledControls & UEFlag::kConsole) != UEFlag::kNone; }
		constexpr bool	 IsFightingControlsEnabled() const noexcept { return (enabledControls & UEFlag::kFighting) != UEFlag::kNone; }
		constexpr bool	 IsLookingControlsEnabled() const noexcept { return (enabledControls & UEFlag::kLooking) != UEFlag::kNone; }
		constexpr bool	 IsMenuControlsEnabled() const noexcept { return (enabledControls & UEFlag::kMenu) != UEFlag::kNone; }
		constexpr bool	 IsMainFourControlsEnabled() const noexcept { return (enabledControls & UEFlag::kMainFour) != UEFlag::kNone; }
		constexpr bool	 IsMovementControlsEnabled() const noexcept { return (enabledControls & UEFlag::kMovement) != UEFlag::kNone; }
		constexpr bool	 IsPOVSwitchControlsEnabled() const noexcept { return (enabledControls & UEFlag::kPOVSwitch) != UEFlag::kNone; }
		constexpr bool	 IsSneakingControlsEnabled() const noexcept { return (enabledControls & UEFlag::kSneaking) != UEFlag::kNone; }
		constexpr bool	 IsVATSControlsEnabled() const noexcept { return (enabledControls & UEFlag::kVATS) != UEFlag::kNone; }
		constexpr bool	 IsWheelZoomControlsEnabled() const noexcept { return (enabledControls & UEFlag::kWheelZoom) != UEFlag::kNone; }
		void			 ToggleControls(UEFlag a_flags, bool a_enable);


		// members
		InputContext*			 controlMap[InputContextID::kTotal];  // 060
		BSTArray<LinkedMapping>	 linkedMappings;					  // 0E8
		BSTArray<InputContextID> contextPriorityStack;				  // 100
		UEFlag					 enabledControls;					  // 118
		UEFlag					 unk11C;							  // 11C
		SInt8					 textEntryCount;					  // 120
		bool					 ignoreKeyboardMouse;				  // 121
		bool					 ignoreActivateDisabledEvents;		  // 122
		UInt8					 pad123;							  // 123
		PC_GAMEPAD_TYPE			 gamePadMapType;					  // 124
	};
	STATIC_ASSERT(sizeof(ControlMap) == 0x128);
}
