#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	struct TESGrabReleaseEvent
	{
	public:
		NiPointer<TESObjectREFR> ref;      // 00
		bool                     grabbed;  // 08
		std::uint8_t             pad09;    // 09
		std::uint16_t            pad0A;    // 09
		std::uint32_t            pad0C;    // 0C
	};
	static_assert(sizeof(TESGrabReleaseEvent) == 0x10);
}
