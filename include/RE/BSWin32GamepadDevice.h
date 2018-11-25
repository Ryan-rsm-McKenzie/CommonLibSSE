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


		virtual bool	IsEnabled(void) const override;	// 7 - { return isConnected && userIndex != -1; } - xref 0x00C17600 - 1_5_53


		// members
		UInt64	pad0B8;			// 0B8
		UInt64	pad0C0;			// 0C0
		SInt32	userIndex;		// 0C8 - init'd -1
		bool	isConnected;	// 0CC - init'd false
		bool	unk0CD;			// 0CD - init'd false
		UInt16	pad0CE;			// 0CE
		UInt64	pad0D0;			// 0D0
		UInt32	pad0D8;			// 0D8
		UInt8	pad0DC;			// 0DC
		UInt8	curState;		// 0DD
		UInt16	pad0DE;			// 0DE
		UInt64	pad0E0;			// 0E0
		UInt64	pad0E8;			// 0E8
		float	curLX;			// 0F0
		float	curLY;			// 0F4
		float	curRX;			// 0F8
		float	curRY;			// 0FC
		UInt32	pad100;			// 100
		UInt8	pad104;			// 104
		UInt8	prevState;		// 105
		UInt16	pad106;			// 106
		UInt64	pad108;			// 108
		UInt64	pad110;			// 110
		float	prevLX;			// 118
		float	prevLY;			// 11C
		float	prevRX;			// 120
		float	prevRY;			// 124
	};
	STATIC_ASSERT(offsetof(BSWin32GamepadDevice, userIndex) == 0x0C8);
	STATIC_ASSERT(offsetof(BSWin32GamepadDevice, isConnected) == 0x0CC);
	STATIC_ASSERT(offsetof(BSWin32GamepadDevice, curState) == 0x0DD);
	STATIC_ASSERT(offsetof(BSWin32GamepadDevice, curLX) == 0x0F0);
	STATIC_ASSERT(offsetof(BSWin32GamepadDevice, curLY) == 0x0F4);
	STATIC_ASSERT(offsetof(BSWin32GamepadDevice, curRX) == 0x0F8);
	STATIC_ASSERT(offsetof(BSWin32GamepadDevice, curRY) == 0x0FC);
	STATIC_ASSERT(offsetof(BSWin32GamepadDevice, prevState) == 0x105);
	STATIC_ASSERT(offsetof(BSWin32GamepadDevice, prevLX) == 0x118);
	STATIC_ASSERT(offsetof(BSWin32GamepadDevice, prevLY) == 0x11C);
	STATIC_ASSERT(offsetof(BSWin32GamepadDevice, prevRX) == 0x120);
	STATIC_ASSERT(offsetof(BSWin32GamepadDevice, prevRY) == 0x124);
}
