#pragma once


namespace RE
{
	struct TESUniqueIDChangeEvent
	{
		UInt32	oldFormID;		// 00
		UInt32	ownerFormID;	// 04
		UInt32	newFormID;		// 08
		UInt16	oldUniqueID;	// 0C
		UInt16	newUniqueID;	// 0E
	};
	STATIC_ASSERT(sizeof(TESUniqueIDChangeEvent) == 0x10);
}
