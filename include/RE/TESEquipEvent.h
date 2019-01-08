#pragma once

#include "RE/FormTypes.h"  // TESObjectREFR


namespace RE
{
	struct TESEquipEvent
	{
		TESObjectREFR*	akSource;		// 00
		UInt32			formID;			// 08
		UInt32			unk0C;			// 0C - formID of a ref handle
		UInt16			unk10;			// 10 - Related to ExtraUniqueID::uniqueID (0x14)
		bool			isEquipping;	// 12
		UInt8			pad13;			// 13
		UInt32			pad14;			// 14
	};
	STATIC_ASSERT(sizeof(TESEquipEvent) == 0x18);
}
