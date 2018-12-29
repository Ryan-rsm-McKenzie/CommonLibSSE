#pragma once

#include "RE/BSInputDevice.h"  // BSInputDevice


namespace RE
{
	class BSMouseDevice : public BSInputDevice
	{
	public:
		virtual ~BSMouseDevice();	// 00

		// add
		virtual void Unk_09(void);	// 09


		// members
		UInt64 unk78;	// 70
	};
	STATIC_ASSERT(sizeof(BSMouseDevice) == 0x78);
}
