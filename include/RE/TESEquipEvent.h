#pragma once

#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class TESObjectREFR;


	struct TESEquipEvent
	{
		NiPointer<TESObjectREFR>	source;			// 00
		FormID						itemID;			// 08
		FormID						equippedBy;		// 0C
		UInt16						uniqueID;		// 10
		bool						isEquipping;	// 12
		UInt8						pad13;			// 13
		UInt32						pad14;			// 14
	};
	STATIC_ASSERT(sizeof(TESEquipEvent) == 0x18);
}
