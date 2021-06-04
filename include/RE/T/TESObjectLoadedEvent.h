#pragma once

namespace RE
{
	struct TESObjectLoadedEvent
	{
	public:
		// members
		FormID        formID;  // 0
		bool          loaded;  // 4
		std::uint8_t  pad5;    // 5
		std::uint16_t pad6;    // 6
	};
	static_assert(sizeof(TESObjectLoadedEvent) == 0x8);
}
