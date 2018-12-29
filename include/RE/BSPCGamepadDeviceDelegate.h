#pragma once

#include "RE/BSGamepadDevice.h"  // BSGamepadDevice


namespace RE
{
	class BSPCGamepadDeviceDelegate : public BSGamepadDevice
	{};
	STATIC_ASSERT(sizeof(BSPCGamepadDeviceDelegate) == 0xD0);
}
