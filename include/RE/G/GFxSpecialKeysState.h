#pragma once

namespace RE
{
	class GFxSpecialKeysState
	{
	public:
		enum class Key
		{
			kShiftPressed = 1 << 0,
			kCtrlPressed = 1 << 1,
			kAltPressed = 1 << 2,
			kCapsToggled = 1 << 3,
			kNumToggled = 1 << 4,
			kScrollToggled = 1 << 5,

			kInitializedBit = 1 << 7,
			kInitializedMask = 0xFF
		};

		std::uint8_t states;  // 0
	};
	static_assert(sizeof(GFxSpecialKeysState) == 0x1);
}
