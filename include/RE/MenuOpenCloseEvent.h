#pragma once

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class MenuOpenCloseEvent
	{
	public:
		BSFixedString	menuName;	// 00
		bool			isOpening;	// 08
		UInt8			pad09;		// 09
		UInt16			pad0A;		// 0A
		UInt32			pad0C;		// 0C
	};
	STATIC_ASSERT(sizeof(MenuOpenCloseEvent) == 0x10);
}
