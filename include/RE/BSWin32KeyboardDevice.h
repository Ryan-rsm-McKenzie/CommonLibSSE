#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSWin32KeyboardDevice

#include "RE/BSKeyboardDevice.h"  // BSKeyboardDevice


namespace RE
{
	class BSWin32KeyboardDevice : public BSKeyboardDevice
	{
	public:
		inline static const void* RTTI = RTTI_BSWin32KeyboardDevice;


		virtual ~BSWin32KeyboardDevice();				// 00

		// override (BSKeyboardDevice)
		virtual void	Initialize() override;			// 01
		virtual	void	Process(float a_unk1) override;	// 02
		virtual	void	Unk_03(void) override;			// 03
		virtual void	Unk_08(void) override;			// 08
		virtual void	Unk_09(void) override;			// 09
		virtual void	Unk_0A(void) override;			// 0A

		bool			IsPressed(UInt32 a_keyCode) const;


		// members
		UInt64	unk070;				// 070
		UInt64	unk078;				// 078
		UInt64	unk080;				// 080
		UInt64	unk088;				// 088
		UInt64	unk090;				// 090
		UInt64	unk098;				// 098
		UInt64	unk0A0;				// 0A0
		UInt64	unk0A8;				// 0A8
		UInt64	unk0B0;				// 0B0
		UInt64	unk0B8;				// 0B8
		UInt64	unk0C0;				// 0C0
		UInt64	unk0C8;				// 0C8
		UInt64	unk0D0;				// 0D0
		UInt64	unk0D8;				// 0D8
		UInt64	unk0E0;				// 0E0
		UInt64	unk0E8;				// 0E8
		UInt64	unk0F0;				// 0F0
		UInt64	unk0F8;				// 0F8
		UInt64	unk100;				// 100
		UInt64	unk108;				// 108
		UInt64	unk110;				// 110
		UInt64	unk118;				// 118
		UInt64	unk120;				// 120
		UInt64	unk128;				// 128
		UInt64	unk130;				// 130
		UInt64	unk138;				// 138
		UInt64	unk140;				// 140
		UInt64	unk148;				// 148
		UInt64	unk150;				// 150
		UInt64	unk158;				// 158
		UInt64	unk160;				// 160
		UInt8	curState[0x100];	// 168
		UInt8	prevState[0x100];	// 268
		UInt64	unk368;				// 368
	};
	STATIC_ASSERT(offsetof(BSWin32KeyboardDevice, curState) == 0x168);
	STATIC_ASSERT(offsetof(BSWin32KeyboardDevice, prevState) == 0x268);
	STATIC_ASSERT(sizeof(BSWin32KeyboardDevice) == 0x370);
}
