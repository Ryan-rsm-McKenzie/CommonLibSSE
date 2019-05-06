#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSIInputDevice.h"  // BSIInputDevice
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/DeviceTypes.h"  // DeviceType


namespace RE
{
	class BSInputDevice : public BSIInputDevice
	{
	public:
		struct Data
		{
			BSFixedString	name;	// 00
			float			timer;	// 08
			UInt32			pad0C;	// 0C
		};


		virtual ~BSInputDevice();					// 00

		// override (BSIInputDevice)
		virtual bool IsEnabled() const override;	// 07

		bool		IsKeyboard() const;
		bool		IsMouse() const;
		bool		IsGamepad() const;
		bool		IsPressed(UInt32 a_keyCode) const;


		// members
		DeviceType					deviceType;	// 08
		UInt32						pad0C;		// 0C
		BSTHashMap<UInt32, Data*>	codeMap;	// 10
		UInt64						unk40;		// 40
		UInt64						unk48;		// 48
		UInt64						unk50;		// 50
		UInt64						unk58;		// 58
		UInt64						unk60;		// 60
		UInt64						unk68;		// 68
	};
	STATIC_ASSERT(offsetof(BSInputDevice, deviceType) == 0x08);
	STATIC_ASSERT(offsetof(BSInputDevice, codeMap) == 0x10);
	STATIC_ASSERT(sizeof(BSInputDevice) == 0x70);
}
