#pragma once


#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESOpenCloseEvent
	{
		NiPointer<TESObjectREFR> ref;		 // 00
		NiPointer<TESObjectREFR> activeRef;	 // 08
		bool					 opened;	 // 10
		UInt8					 pad11;		 // 11
		UInt16					 pad12;		 // 12
		UInt32					 pad14;		 // 14
	};
	STATIC_ASSERT(sizeof(TESOpenCloseEvent) == 0x18);
}
