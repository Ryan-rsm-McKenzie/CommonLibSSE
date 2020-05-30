#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESMoveAttachDetachEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> movedRef;		  // 00
		bool					 isCellAttached;  // 08
		UInt8					 pad09;			  // 09
		UInt16					 pad0A;			  // 0A
		UInt32					 pad0C;			  // 0C
	};
	STATIC_ASSERT(sizeof(TESMoveAttachDetachEvent) == 0x10);
}
