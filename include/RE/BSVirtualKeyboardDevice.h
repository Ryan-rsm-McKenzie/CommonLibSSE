#pragma once

#include "RE/BSKeyboardDevice.h"  // BSKeyboardDevice


namespace RE
{
	class BSVirtualKeyboardDevice : public BSKeyboardDevice
	{
	public:
		virtual ~BSVirtualKeyboardDevice();	// 00

		// add
		virtual void	Unk_0B(void);		// 0B - pure
		virtual void	Unk_0C(void);		// 0C - pure
		virtual void	Unk_0D(void);		// 0D - pure
	};
	STATIC_ASSERT(sizeof(BSVirtualKeyboardDevice) == 0x70);
}
