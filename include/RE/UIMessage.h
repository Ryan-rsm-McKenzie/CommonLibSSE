#pragma once

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class IUIMessageData;


	class UIMessage
	{
	public:
		enum class Message : UInt32
		{
			kRefresh = 0,
			kOpen = 1,
			kClose = 3,
			kScaleform = 6,	// BSUIScaleformData
			kMessage = 7,	// BSUIMessageData
			kUnk13 = 13
		};


		BSFixedString	strData;	// 00
		Message			message;	// 08
		UInt32			pad0C;		// 0C
		IUIMessageData*	objData;	// 10
		bool			isPooled;	// 18
		UInt8			pad19;		// 19
		UInt16			pad1A;		// 1A
		UInt32			pad1C;		// 1C
	};
	STATIC_ASSERT(sizeof(UIMessage) == 0x20);
}
