#pragma once

#include "RE/B/BSKeyboardDevice.h"

namespace RE
{
	class BSVirtualKeyboardDevice : public BSKeyboardDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSVirtualKeyboardDevice;

		virtual ~BSVirtualKeyboardDevice();	 // 00

		// override (BSKeyboardDevice)
		virtual void Unk_09(void) override;	 // 09 - { return; }
		virtual void Unk_0A(void) override;	 // 0A - { return; }

		// add
		virtual void Unk_0B(void) = 0;	// 0B
		virtual void Unk_0C(void) = 0;	// 0C
		virtual void Unk_0D(void) = 0;	// 0D
	};
	static_assert(sizeof(BSVirtualKeyboardDevice) == 0x70);
}
