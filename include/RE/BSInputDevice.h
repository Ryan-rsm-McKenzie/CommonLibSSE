#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSIInputDevice.h"  // BSIInputDevice
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/InputEvent.h"  // InputEvent::DeviceType


namespace RE
{
	class BSInputDevice : public BSIInputDevice
	{
	private:
		typedef InputEvent::DeviceType DeviceType;

	public:
		struct Data
		{
			BSFixedString	name;	// 00
			float			timer;	// 08
			UInt32			pad0C;	// 0C
		};


		virtual ~BSInputDevice();							// 0

		virtual void	Initialize() = 0;					// 1
		virtual	void	Process(float a_unk1) = 0;			// 2
		virtual	void	Unk_03() = 0;						// 3
		virtual	void	Unk_04();							// 4
		virtual void	Unk_05();							// 5
		virtual void	Unk_06();							// 6
		virtual bool	IsEnabled() const;					// 7
		virtual void	Unk_08();							// 8

		bool			IsKeyboard() const;
		bool			IsMouse() const;
		bool			IsGamepad() const;
		bool			IsPressed(UInt32 keyCode) const;


		// members
		DeviceType					type;		// 08
		UInt32						pad0C;		// 0C
		BSTHashMap<UInt32, Data*>	codeMap;	// 10
	};
	STATIC_ASSERT(offsetof(BSInputDevice, type) == 0x08);
	STATIC_ASSERT(offsetof(BSInputDevice, codeMap) == 0x10);
	STATIC_ASSERT(sizeof(BSInputDevice::codeMap) == 0x30);
}
