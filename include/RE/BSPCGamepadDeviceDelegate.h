#pragma once

#include "RE/BSGamepadDevice.h"  // BSGamepadDevice


namespace RE
{
	class BSPCGamepadDeviceDelegate : public BSGamepadDevice
	{
	public:
		virtual ~BSPCGamepadDeviceDelegate();			// 00

		// override (BSGamepadDevice)
		virtual void	Initialize() override;			// 01
		virtual	void	Process(float a_unk1) override;	// 02


		// members
		UInt64 unkD0;	// D0
	};
	STATIC_ASSERT(sizeof(BSPCGamepadDeviceDelegate) == 0xD8);
}
