#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	struct TESFurnitureEvent
	{
	public:
		enum class FurnitureEventType
		{
			kEnter = 0,
			kExit = 1
		};

		// members
		NiPointer<TESObjectREFR>                            actor;            // 00
		NiPointer<TESObjectREFR>                            targetFurniture;  // 08
		stl::enumeration<FurnitureEventType, std::uint32_t> type;             // 10
	};
	static_assert(sizeof(TESFurnitureEvent) == 0x18);
}
