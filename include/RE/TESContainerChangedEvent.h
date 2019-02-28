#pragma once


namespace RE
{
	struct TESContainerChangedEvent
	{
	public:
		UInt32	fromFormID;		// 00
		UInt32	toFormID;		// 04
		UInt32	itemFormID;		// 08
		UInt32	count;			// 0C
		UInt32	toReference;	// 10
		UInt16	unk14;			// 14
		UInt16	pad16;			// 16
	};
	STATIC_ASSERT(sizeof(TESContainerChangedEvent) == 0x18);
}
