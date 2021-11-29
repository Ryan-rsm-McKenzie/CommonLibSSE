#pragma once

#include "RE/B/BSGamepadDevice.h"

namespace RE
{
	class BSPCGamepadDeviceHandler;

	class BSPCGamepadDeviceDelegate : public BSGamepadDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSPCGamepadDeviceDelegate;

		~BSPCGamepadDeviceDelegate() override;  // 00

		// override (BSGamepadDevice)
		void Initialize() override;           // 01 - { return; }
		void Process(float a_arg1) override;  // 02 - { return; }
		void Unk_03(void) override;           // 03 - { return; }
		void Reset() override;                // 08 - { return; }
		void Unk_09(void) override;           // 09 - { return; }

		// members
		BSPCGamepadDeviceHandler* gamepadDeviceHandler;  // D0
	};
	static_assert(sizeof(BSPCGamepadDeviceDelegate) == 0xD8);
}
