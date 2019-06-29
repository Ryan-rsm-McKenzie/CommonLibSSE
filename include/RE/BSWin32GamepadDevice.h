#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSWin32GamepadDevice

#include "RE/BSPCGamepadDeviceDelegate.h"  // BSPCGamepadDeviceDelegate


namespace RE
{
	class BSWin32GamepadDevice : public BSPCGamepadDeviceDelegate
	{
	public:
		inline static const void* RTTI = RTTI_BSWin32GamepadDevice;


		struct Keys
		{
			enum Key : UInt32
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
				kLeftTrigger = 0x0009,
				kRightTrigger = 0x000A
			};
		};
		using Key = Keys::Key;


		virtual ~BSWin32GamepadDevice();				// 00

		// override (BSPCGamepadDeviceDelegate)
		virtual void	Initialize() override;			// 01
		virtual	void	Process(float a_arg1) override;	// 02
		virtual	void	Unk_03(void) override;			// 03
		virtual void	Unk_08(void) override;			// 08
		virtual void	Unk_09(void) override;			// 09


		// members
		UInt32	unk0D8;		// 0D8
		UInt8	unk0DC;		// 0DC
		UInt8	curState;	// 0DD
		UInt16	unk0DE;		// 0DE
		UInt64	unk0E0;		// 0E0
		UInt64	unk0E8;		// 0E8
		float	curLX;		// 0F0
		float	curLY;		// 0F4
		float	curRX;		// 0F8
		float	curRY;		// 0FC
		UInt32	unk100;		// 100
		UInt8	unk104;		// 104
		UInt8	prevState;	// 105
		UInt16	unk106;		// 106
		UInt64	unk108;		// 108
		UInt64	unk110;		// 110
		float	prevLX;		// 118
		float	prevLY;		// 11C
		float	prevRX;		// 120
		float	prevRY;		// 124
	};
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
	STATIC_ASSERT(sizeof(BSWin32GamepadDevice) == 0x128);
}
