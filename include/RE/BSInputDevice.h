#pragma once

#include "skse64/GameTypes.h"  // BSFixedString

#include "RE/BSIInputDevice.h"  // BSIInputDevice
#include "RE/BSTHashMap.h"  // BSTHashMap


namespace RE
{
	class BSInputDevice : public BSIInputDevice
	{
	public:
		enum InputDevice : UInt32
		{
			kInputDevice_Keyboard = 0,
			kInputDevice_Mouse,
			kInputDevice_Gamepad
		};


		struct Data
		{
			BSFixedString	name;	// 00
			float			timer;	// 08
			UInt32			pad0C;	// 0C
		};


		virtual ~BSInputDevice();

		virtual void	Initialize() = 0;
		virtual	void	Process(float unk1) = 0;
		virtual	void	Unk_03() = 0;
		virtual	bool	Unk_04(UInt32 unk0, void *unk1);
		virtual bool	Unk_05(void *unk0);
		virtual bool	Unk_06(UInt32 unk0, UInt32 *unk1);
		virtual bool	IsEnabled(void) const;
		virtual void	Unk_08(void* unk1);

		bool			IsKeyboard() const;
		bool			IsMouse() const;
		bool			IsGamepad() const;
		bool			IsPressed(UInt32 keyCode) const;


		// members
		InputDevice					type;		// 08
		UInt32						pad0C;		// 0C
		BSTHashMap<UInt32, Data*>	codeMap;	// 10
	};
	STATIC_ASSERT(offsetof(BSInputDevice, type) == 0x08);
	STATIC_ASSERT(offsetof(BSInputDevice, codeMap) == 0x10);
	STATIC_ASSERT(sizeof(BSInputDevice::codeMap) == 0x30);
}
