#pragma once

#include <string_view>
#include <type_traits>

#include "RE/BSFixedString.h"
#include "RE/BSInputDevice.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTSingleton.h"
#include "RE/InputDevices.h"
#include "RE/PCGamepadType.h"
#include "RE/UserEvents.h"


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
		bool			 AreControlsEnabled(UEFlag a_flags) const;
		UInt32			 GetMappedKey(const std::string_view& a_eventID, INPUT_DEVICE a_device, InputContextID a_context = InputContextID::kGameplay) const;
		std::string_view GetUserEventName(UInt32 a_buttonID, INPUT_DEVICE a_device, InputContextID a_context = InputContextID::kGameplay) const;
		bool			 IsActivateControlsEnabled() const;
		bool			 IsConsoleControlsEnabled() const;
		bool			 IsFightingControlsEnabled() const;
		bool			 IsLookingControlsEnabled() const;
		bool			 IsMenuControlsEnabled() const;
		bool			 IsMainFourControlsEnabled() const;
		bool			 IsMovementControlsEnabled() const;
		bool			 IsPOVSwitchControlsEnabled() const;
		bool			 IsSneakingControlsEnabled() const;
		bool			 IsVATSControlsEnabled() const;
		bool			 IsWheelZoomControlsEnabled() const;
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
