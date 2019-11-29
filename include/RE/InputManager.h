#pragma once

#include "RE/BSTEvent.h"
#include "RE/BSTSingleton.h"


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


	class InputManager :
		public BSTEventSource<InputEvent*>,		// 00
		public BSTSingletonSDM<InputManager>	// 58
	{
	public:
		struct Devices
		{
			enum Device
			{
				kKeyboard,
				kMouse,
				kGamepadHandler,
				kVirtualKeyboard,

				kTotal
			};
		};
		using Device = Devices::Device;


		static InputManager* GetSingleton();

		BSPCGamepadDeviceDelegate*		GetGamepad();
		BSPCGamepadDeviceHandler*		GetGamepadHandler();
		BSWin32KeyboardDevice*			GetKeyboard();
		BSWin32MouseDevice*				GetMouse();
		BSWin32VirtualKeyboardDevice*	GetVirtualKeyboard();
		bool							IsGamepadConnected();
		bool							IsGamepadEnabled();


		// members
		UInt8									pad59;						// 59
		UInt16									pad5A;						// 5A
		UInt32									pad5C;						// 5C
		BSIInputDevice*							devices[Device::kTotal];	// 60
		bool									unk80;						// 80
		bool									unk81;						// 81
		UInt16									pad82;						// 82
		UInt32									pad84;						// 84
		BSTEventSource<BSRemoteGamepadEvent>	remoteGamepadEventSource;	// 88
		UInt8									unkE0;						// E0
		UInt8									unkE1;						// E1
		UInt16									unkE2;						// E2
		UInt32									unkE4;						// E4
		UInt64									unkE8;						// E8
	};
	STATIC_ASSERT(sizeof(InputManager) == 0xF0);
}
