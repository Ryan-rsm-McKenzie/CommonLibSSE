#pragma once

namespace RE
{
	struct INPUT_DEVICES
	{
		enum INPUT_DEVICE
		{
			kNone = static_cast<std::underlying_type_t<INPUT_DEVICE>>(-1),
			kKeyboard = 0,
			kMouse,
			kGamepad,
			kVirtualKeyboard,

			kTotal
		};
	};
	using INPUT_DEVICE = INPUT_DEVICES::INPUT_DEVICE;
}
