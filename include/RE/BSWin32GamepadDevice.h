#pragma once

#include "RE/BSPCGamepadDeviceDelegate.h"  // BSPCGamepadDeviceDelegate


namespace RE
{
	class BSWin32GamepadDevice : public BSPCGamepadDeviceDelegate
	{
	public:
		enum Gamepad : UInt32
		{
			kGamepad_Up				= 0x0001,
			kGamepad_Down			= 0x0002,
			kGamepad_Left			= 0x0004,
			kGamepad_Right			= 0x0008,
			kGamepad_Start			= 0x0010,
			kGamepad_Back			= 0x0020,
			kGamepad_LeftThumb		= 0x0040,
			kGamepad_RightThumb		= 0x0080,
			kGamepad_LeftShoulder	= 0x0100,
			kGamepad_RightShoulder	= 0x0200,
			kGamepad_A				= 0x1000,
			kGamepad_B				= 0x2000,
			kGamepad_X				= 0x4000,
			kGamepad_Y				= 0x8000,
			kGamepad_LT				= 0x0009,
			kGamepad_RT				= 0x000A
		};

		// members
		UInt8	pad030[0xAD];	// 030
		UInt8	curState;		// 0DD
		UInt8	pad0DE[0x27];	// 0DE
		UInt8	prevState;		// 105
	};
}
