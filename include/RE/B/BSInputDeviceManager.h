#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/I/InputDevices.h"

namespace RE
{
	class BSIInputDevice;
	class BSPCGamepadDeviceDelegate;
	class BSPCGamepadDeviceHandler;
	class BSWin32KeyboardDevice;
	class BSWin32MouseDevice;
	class BSWin32VirtualKeyboardDevice;
	class InputEvent;
	struct BSRemoteGamepadEvent;

	class BSInputDeviceManager :
		public BSTEventSource<InputEvent*>,			  // 00
		public BSTSingletonSDM<BSInputDeviceManager>  // 58
	{
	public:
		static BSInputDeviceManager* GetSingleton();

		BSPCGamepadDeviceDelegate*	  GetGamepad();
		BSPCGamepadDeviceHandler*	  GetGamepadHandler();
		BSWin32KeyboardDevice*		  GetKeyboard();
		BSWin32MouseDevice*			  GetMouse();
		BSWin32VirtualKeyboardDevice* GetVirtualKeyboard();
		bool						  IsGamepadConnected();
		bool						  IsGamepadEnabled();

		// members
		std::uint8_t						 pad59;							  // 59
		std::uint16_t						 pad5A;							  // 5A
		std::uint32_t						 pad5C;							  // 5C
		BSIInputDevice*						 devices[INPUT_DEVICES::kTotal];  // 60
		bool								 queuedGamepadEnableValue;		  // 80
		bool								 valueQueued;					  // 81
		bool								 pollingEnabled;				  // 82
		std::uint8_t						 pad83;							  // 83
		std::uint32_t						 pad84;							  // 84
		BSTEventSource<BSRemoteGamepadEvent> remoteGamepadEventSource;		  // 88
		std::uint8_t						 unkE0;							  // E0
		std::uint8_t						 unkE1;							  // E1
		std::uint16_t						 unkE2;							  // E2
		std::uint32_t						 unkE4;							  // E4
		std::uint64_t						 unkE8;							  // E8
	};
	static_assert(sizeof(BSInputDeviceManager) == 0xF0);
}
