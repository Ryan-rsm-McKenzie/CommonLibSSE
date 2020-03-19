#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESEquipEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> actor;			// 00
		FormID					 baseObject;	// 08
		FormID					 originalRefr;	// 0C
		UInt16					 uniqueID;		// 10
		bool					 equipped;		// 12
		UInt8					 pad13;			// 13
		UInt32					 pad14;			// 14
	};
	STATIC_ASSERT(sizeof(TESEquipEvent) == 0x18);
}
