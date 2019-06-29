#pragma once


namespace RE
{
	struct TESContainerChangedEvent
	{
	public:
		FormID		from;		// 00
		FormID		to;			// 04
		FormID		item;		// 08
		SInt32		count;		// 0C
		RefHandle	toRef;		// 10
		UInt16		uniqueID;	// 14
		UInt16		pad16;		// 16
	};
	STATIC_ASSERT(sizeof(TESContainerChangedEvent) == 0x18);
}
