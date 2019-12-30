#pragma once


namespace RE
{
	enum class INPUT_DEVICE : UInt32
	{
		kNone = static_cast<std::underlying_type_t<INPUT_DEVICE>>(-1),
		kKeyboard = 0,
		kMouse,
		kGamepad,
		kVirtualKeyboard,

		kTotal
	};
}
