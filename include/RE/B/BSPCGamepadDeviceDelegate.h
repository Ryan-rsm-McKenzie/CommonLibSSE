#pragma once

#include "RE/B/BSGamepadDevice.h"

namespace RE
{
	class BSPCGamepadDeviceHandler;

	class BSPCGamepadDeviceDelegate : public BSGamepadDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSPCGamepadDeviceDelegate;

		virtual ~BSPCGamepadDeviceDelegate();  // 00

		// override (BSGamepadDevice)
		virtual void Initialize() override;			  // 01 - { return; }
		virtual void Process(float a_arg1) override;  // 02 - { return; }
		virtual void Unk_03(void) override;			  // 03 - { return; }
		virtual void Reset() override;				  // 08 - { return; }
		virtual void Unk_09(void) override;			  // 09 - { return; }

		// members
		BSPCGamepadDeviceHandler* gamepadDeviceHandler;	 // D0
	};
	static_assert(sizeof(BSPCGamepadDeviceDelegate) == 0xD8);
}
