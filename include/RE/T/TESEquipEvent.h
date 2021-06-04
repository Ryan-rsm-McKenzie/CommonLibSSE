#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	struct TESEquipEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> actor;         // 00
		FormID                   baseObject;    // 08
		FormID                   originalRefr;  // 0C
		std::uint16_t            uniqueID;      // 10
		bool                     equipped;      // 12
		std::uint8_t             pad13;         // 13
		std::uint32_t            pad14;         // 14
	};
	static_assert(sizeof(TESEquipEvent) == 0x18);
}
