#pragma once

#include "RE/BSIInputDevice.h"  // BSIInputDevice


namespace RE
{
	class BSGamepadDevice;


	class BSPCGamepadDeviceHandler : public BSIInputDevice
	{
	public:
		virtual ~BSPCGamepadDeviceHandler();

		// override (BSIInputDevice)
		virtual void	Initialize() override;			// 01
		virtual	void	Process(float a_unk1) override;	// 02
		virtual bool	IsEnabled() const override;		// 07 - { return gamepad != 0; }


		// members
		BSGamepadDevice* gamepad;	// 08
	};
	STATIC_ASSERT(sizeof(BSPCGamepadDeviceHandler) == 0x10);
}
