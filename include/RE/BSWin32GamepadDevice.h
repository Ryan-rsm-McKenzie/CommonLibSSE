#pragma once

#include "RE/BSPCGamepadDeviceDelegate.h"  // BSPCGamepadDeviceDelegate


namespace RE
{
	class BSWin32GamepadDevice : public BSPCGamepadDeviceDelegate
	{
	public:
		enum class Gamepad : UInt32
		{
			kUp = 0x0001,
			kDown = 0x0002,
			kLeft = 0x0004,
			kRight = 0x0008,
			kStart = 0x0010,
			kBack = 0x0020,
			kLeftThumb = 0x0040,
			kRightThumb = 0x0080,
			kLeftShoulder = 0x0100,
			kRightShoulder = 0x0200,
			kA = 0x1000,
			kB = 0x2000,
			kX = 0x4000,
			kY = 0x8000,
			kLT = 0x0009,
			kRT = 0x000A
		};


		// override (BSPCGamepadDeviceDelegate)
		virtual bool IsEnabled(void) const override;	// 07 - { return isConnected && userIndex != -1; } - xref 0x00C17600 - 1_5_53


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
