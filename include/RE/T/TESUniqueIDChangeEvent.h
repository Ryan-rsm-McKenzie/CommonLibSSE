#pragma once

namespace RE
{
	struct TESUniqueIDChangeEvent
	{
	public:
		// members
		FormID        oldBaseID;    // 00
		FormID        newBaseID;    // 04
		FormID        objectID;     // 08
		std::uint16_t oldUniqueID;  // 0C
		std::uint16_t newUniqueID;  // 0E
	};
	static_assert(sizeof(TESUniqueIDChangeEvent) == 0x10);
}
