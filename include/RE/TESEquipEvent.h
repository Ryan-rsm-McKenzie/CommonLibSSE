#pragma once

#include "RE/FormTypes.h"  // TESObjectREFR


namespace RE
{
	struct TESEquipEvent
	{
		TESObjectREFR*	akSource;		// 00
		FormID			formID;			// 08
		FormID			unk0C;			// 0C - formID of a ref handle
		UInt16			uniqueID;		// 10
		bool			isEquipping;	// 12
		UInt8			pad13;			// 13
		UInt32			pad14;			// 14
	};
	STATIC_ASSERT(sizeof(TESEquipEvent) == 0x18);
}
