#pragma once

#include "RE/BSKeyboardDevice.h"  // BSKeyboardDevice


namespace RE
{
	class BSWin32KeyboardDevice : public BSKeyboardDevice
	{
	public:
		enum Keyboard : UInt32
		{
			kKeyboard_Escape		= 0x01,
			kKeyboard_Num1			= 0x02,
			kKeyboard_Num2			= 0x03,
			kKeyboard_Num3			= 0x04,
			kKeyboard_Num4			= 0x05,
			kKeyboard_Num5			= 0x06,
			kKeyboard_Num6			= 0x07,
			kKeyboard_Num7			= 0x08,
			kKeyboard_Num8			= 0x09,
			kKeyboard_Num9			= 0x0A,
			kKeyboard_Num0			= 0x0B,
			kKeyboard_Minus			= 0x0C,
			kKeyboard_Equals		= 0x0D,
			kKeyboard_Backspace		= 0x0E,
			kKeyboard_Tab			= 0x0F,
			kKeyboard_Q				= 0x10,
			kKeyboard_W				= 0x11,
			kKeyboard_E				= 0x12,
			kKeyboard_R				= 0x13,
			kKeyboard_T				= 0x14,
			kKeyboard_Y				= 0x15,
			kKeyboard_U				= 0x16,
			kKeyboard_I				= 0x17,
			kKeyboard_O				= 0x18,
			kKeyboard_P				= 0x19,
			kKeyboard_BracketLeft	= 0x1A,
			kKeyboard_BracketRight	= 0x1B,
			kKeyboard_Enter			= 0x1C,
			kKeyboard_LeftControl	= 0x1D,
			kKeyboard_A				= 0x1E,
			kKeyboard_S				= 0x1F,
			kKeyboard_D				= 0x20,
			kKeyboard_F				= 0x21,
			kKeyboard_G				= 0x22,
			kKeyboard_H				= 0x23,
			kKeyboard_J				= 0x24,
			kKeyboard_K				= 0x25,
			kKeyboard_L				= 0x26,
			kKeyboard_Semicolon		= 0x27,
			kKeyboard_Apostrophe	= 0x28,
			kKeyboard_Tilda			= 0x29,
			kKeyboard_LeftShift		= 0x2A,
			kKeyboard_Backslash		= 0x2B,
			kKeyboard_Z				= 0x2C,
			kKeyboard_X				= 0x2D,
			kKeyboard_C				= 0x2E,
			kKeyboard_V				= 0x2F,
			kKeyboard_B				= 0x30,
			kKeyboard_N				= 0x31,
			kKeyboard_M				= 0x32,
			kKeyboard_Comma			= 0x33,
			kKeyboard_Period		= 0x34,
			kKeyboard_Slash			= 0x35,
			kKeyboard_RightShift	= 0x36,
			kKeyboard_KP_Multiply	= 0x37,
			kKeyboard_LeftAlt		= 0x38,
			kKeyboard_Spacebar		= 0x39,
			kKeyboard_CapsLock		= 0x3A,
			kKeyboard_F1			= 0x3B,
			kKeyboard_F2			= 0x3C,
			kKeyboard_F3			= 0x3D,
			kKeyboard_F4			= 0x3E,
			kKeyboard_F5			= 0x3F,
			kKeyboard_F6			= 0x40,
			kKeyboard_F7			= 0x41,
			kKeyboard_F8			= 0x42,
			kKeyboard_F9			= 0x43,
			kKeyboard_F10			= 0x44,
			kKeyboard_NumLock		= 0x45,
			kKeyboard_ScrollLock	= 0x46,
			kKeyboard_KP_7			= 0x47,
			kKeyboard_KP_8			= 0x48,
			kKeyboard_KP_9			= 0x49,
			kKeyboard_KP_Subtract	= 0x4A,
			kKeyboard_KP_4			= 0x4B,
			kKeyboard_KP_5			= 0x4C,
			kKeyboard_KP_6			= 0x4D,
			kKeyboard_KP_Plus		= 0x4E,
			kKeyboard_KP_1			= 0x4F,
			kKeyboard_KP_2			= 0x50,
			kKeyboard_KP_3			= 0x51,
			kKeyboard_KP_0			= 0x52,
			kKeyboard_KP_Decimal	= 0x53,
			kKeyboard_F11			= 0x57,
			kKeyboard_F12			= 0x58,
			kKeyboard_KP_Enter		= 0x9C,
			kKeyboard_RightControl	= 0x9D,
			kKeyboard_KP_Divide		= 0xB5,
			kKeyboard_PrintScreen	= 0xB7,
			kKeyboard_RightAlt		= 0xB8,
			kKeyboard_Pause			= 0xC5,
			kKeyboard_Home			= 0xC7,
			kKeyboard_Up			= 0xC8,
			kKeyboard_PageUp		= 0xC9,
			kKeyboard_Left			= 0xCB,
			kKeyboard_Right			= 0xCD,
			kKeyboard_End			= 0xCF,
			kKeyboard_Down			= 0xD0,
			kKeyboard_PageDown		= 0xD1,
			kKeyboard_Insert		= 0xD2,
			kKeyboard_Delete		= 0xD3
		};


		bool	IsPressed(UInt32 keyCode) const;


		// members
		void*		inputDevice;		// 040 - IDirectInputDevice8*
		UInt8		pad048[0x120];		// 048
		UInt8		curState[0x100];	// 168
		UInt8		prevState[0x100];	// 268
	};
	STATIC_ASSERT(offsetof(BSWin32KeyboardDevice, inputDevice) == 0x40);
	STATIC_ASSERT(offsetof(BSWin32KeyboardDevice, curState) == 0x168);
	STATIC_ASSERT(offsetof(BSWin32KeyboardDevice, prevState) == 0x268);
}
