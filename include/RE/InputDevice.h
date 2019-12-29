#pragma once


namespace RE
{
	enum class InputDevice : UInt32
	{
		kNone = static_cast<std::underlying_type_t<InputDevice>>(-1),
		kKeyboard = 0,
		kMouse,
		kGamepad,
		kVirtualKeyboard,

		kTotal
	};
}
