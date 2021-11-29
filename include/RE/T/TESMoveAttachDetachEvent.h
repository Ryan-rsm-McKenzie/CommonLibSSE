#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	struct TESMoveAttachDetachEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> movedRef;        // 00
		bool                     isCellAttached;  // 08
		std::uint8_t             pad09;           // 09
		std::uint16_t            pad0A;           // 0A
		std::uint32_t            pad0C;           // 0C
	};
	static_assert(sizeof(TESMoveAttachDetachEvent) == 0x10);
}
