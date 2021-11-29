#pragma once

#include "RE/B/BSVirtualKeyboardDevice.h"

namespace RE
{
	class BSWin32VirtualKeyboardDevice : public BSVirtualKeyboardDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSWin32VirtualKeyboardDevice;

		~BSWin32VirtualKeyboardDevice() override;  // 00

		// override (BSVirtualKeyboardDevice)
		void Initialize() override;           // 01 - { return; }
		void Process(float a_arg1) override;  // 02 - { return; }
		void Unk_03(void) override;           // 03 - { return; }
		void Reset() override;                // 08 - { return; }
		void Unk_0B(void) override;           // 0B - { return; }
		void Unk_0C(void) override;           // 0C - { return; }
		void Unk_0D(void) override;           // 0D - { return; }
	};
	static_assert(sizeof(BSWin32VirtualKeyboardDevice) == 0x70);
}
