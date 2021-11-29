#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	struct TESOpenCloseEvent
	{
		NiPointer<TESObjectREFR> ref;        // 00
		NiPointer<TESObjectREFR> activeRef;  // 08
		bool                     opened;     // 10
		std::uint8_t             pad11;      // 11
		std::uint16_t            pad12;      // 12
		std::uint32_t            pad14;      // 14
	};
	static_assert(sizeof(TESOpenCloseEvent) == 0x18);
}
