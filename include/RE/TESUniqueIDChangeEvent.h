#pragma once


namespace RE
{
	struct TESUniqueIDChangeEvent
	{
		FormID	oldOwnerID;		// 00
		FormID	newOwnerID;		// 04
		FormID	itemID;			// 08
		UInt16	oldUniqueID;	// 0C
		UInt16	newUniqueID;	// 0E
	};
	STATIC_ASSERT(sizeof(TESUniqueIDChangeEvent) == 0x10);
}
