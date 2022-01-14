#pragma once

namespace RE
{
	class TESObjectREFR;

	struct TESFormDeleteEvent
	{
	public:
		FormID        formID;  // 00
		std::uint32_t pad04;   // 04
	};
	static_assert(sizeof(TESFormDeleteEvent) == 0x08);
}
