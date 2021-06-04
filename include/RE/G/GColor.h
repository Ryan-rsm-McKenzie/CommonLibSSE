#pragma once

namespace RE
{
	class GColor
	{
	public:
		struct RGB32
		{
			std::uint8_t blue;   // 0
			std::uint8_t green;  // 1
			std::uint8_t red;    // 2
			std::uint8_t alpha;  // 3
		};
		static_assert(sizeof(RGB32) == 0x4);

		union ColorData
		{
			RGB32         channels;
			std::uint32_t raw;
		};
		static_assert(sizeof(ColorData) == 0x4);

		// members
		ColorData colorData;  // 0
	};
	static_assert(sizeof(GColor) == 0x4);
}
