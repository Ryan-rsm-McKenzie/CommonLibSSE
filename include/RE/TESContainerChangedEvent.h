#pragma once

#include "RE/BSPointerHandle.h"


namespace RE
{
	struct TESContainerChangedEvent
	{
	public:
		// members
		FormID			oldContainer;  // 00
		FormID			newContainer;  // 04
		FormID			baseObj;	   // 08
		SInt32			itemCount;	   // 0C
		ObjectRefHandle reference;	   // 10
		UInt16			uniqueID;	   // 14
		UInt16			pad16;		   // 16
	};
	STATIC_ASSERT(sizeof(TESContainerChangedEvent) == 0x18);
}
