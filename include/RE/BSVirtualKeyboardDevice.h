#pragma once

#include "RE/BSKeyboardDevice.h"  // BSKeyboardDevice


namespace RE
{
	class BSVirtualKeyboardDevice : public BSKeyboardDevice
	{
	public:
		virtual ~BSVirtualKeyboardDevice();	// 00

		// add
		virtual void	Unk_0B(void) = 0;	// 0B
		virtual void	Unk_0C(void) = 0;	// 0C
		virtual void	Unk_0D(void) = 0;	// 0D
	};
	STATIC_ASSERT(sizeof(BSVirtualKeyboardDevice) == 0x70);
}
