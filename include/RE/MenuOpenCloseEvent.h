#pragma once

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class MenuOpenCloseEvent
	{
	public:
		BSFixedString	menuName;	// 0
		bool			isOpening;	// 8
		UInt8			pad9;		// 9
		UInt16			padA;		// A
		UInt32			padC;		// C
	};
}
