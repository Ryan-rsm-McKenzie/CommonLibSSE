#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class MenuOpenCloseEvent
	{
	public:
		// members
		BSFixedString menuName;  // 00
		bool          opening;   // 08
		std::uint8_t  pad09;     // 09
		std::uint16_t pad0A;     // 0A
		std::uint32_t pad0C;     // 0C
	};
	static_assert(sizeof(MenuOpenCloseEvent) == 0x10);
}
