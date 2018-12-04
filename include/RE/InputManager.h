#pragma once

#include "RE/BSTEvent.h"  // BSTEventSource
#include "RE/InputEvent.h"  // InputEvent


namespace RE
{
	class BSGamepadDevice;
	class BSKeyboardDevice;
	class BSMouseDevice;
	class BSPCGamepadDeviceHandler;
	class BSVirtualKeyboardDevice;


	class InputManager : public BSTEventSource<InputEvent*>
	{
	public:
		static InputManager*	GetSingleton();

		bool					IsGamepadConnected();
		bool					IsGamepadEnabled();
		BSGamepadDevice*		GetGamepad();


		// members
		UInt32						unk58;			// 58
		UInt32						pad5C;			// 5C
		BSKeyboardDevice*			keyboard;		// 60 - BSWin32KeyboardDevice
		BSMouseDevice*				mouse;			// 68 - BSWin32MouseDevice
		BSPCGamepadDeviceHandler*	gamepadHandler;	// 70
		BSVirtualKeyboardDevice*	vitualKeyboard;	// 78 - BSWin32VirtualKeyboardDevice - New in SE
		bool						unk78;			// 80 - init'd true
		bool						unk79;			// 81 - init'd false
		UInt8						pad7A;			// 82
		UInt8						pad7B;			// 83
		UInt32						pad7C;			// 84
	};
	STATIC_ASSERT(offsetof(InputManager, keyboard) == 0x60);
}
