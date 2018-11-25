#pragma once

#include "RE/BSInputDevice.h"  // BSInputDevice


namespace RE
{
	class BSGamepadDevice : public BSInputDevice
	{
	public:
		UInt8	pad40[0x78];	// 40
	};
	STATIC_ASSERT(offsetof(BSGamepadDevice, pad40) == 0x40);
	STATIC_ASSERT(sizeof(BSGamepadDevice) == 0xB8);  // xref 0x00C189F0 + 0x121 - 1_5_53
}
