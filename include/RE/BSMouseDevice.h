#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSMouseDevice

#include "RE/BSInputDevice.h"  // BSInputDevice


namespace RE
{
	class BSMouseDevice : public BSInputDevice
	{
	public:
		inline static const void* RTTI = RTTI_BSMouseDevice;


		virtual ~BSMouseDevice();	// 00

		// add
		virtual void Unk_09(void);	// 09


		// members
		UInt64 unk78;	// 70
	};
	STATIC_ASSERT(sizeof(BSMouseDevice) == 0x78);
}
