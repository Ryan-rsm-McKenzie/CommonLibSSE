#pragma once

#include "RE/BSFixedString.h"


namespace RE
{
	class IUIMessageData;


	enum class UI_MESSAGE_TYPE : UInt32
	{
		kUpdate = 0,
		kShow = 1,
		kReshow = 2,
		kHide = 3,
		kForceHide = 4,

		kScaleformEvent = 6,  // BSUIScaleformData
		kUserEvent = 7,		  // BSUIMessageData
		kInventoryUpdate = 8,
		kUserProfileChange = 9,
		kMUStatusChange = 10,
		kResumeCaching = 11,
		kUpdateController = 12,
		kChatterEvent = 13
	};


	class UIMessage
	{
	public:
		BSFixedString	menu;	   // 00
		UI_MESSAGE_TYPE type;	   // 08
		UInt32			pad0C;	   // 0C
		IUIMessageData* data;	   // 10
		bool			isPooled;  // 18
		UInt8			pad19;	   // 19
		UInt16			pad1A;	   // 1A
		UInt32			pad1C;	   // 1C
	};
	STATIC_ASSERT(sizeof(UIMessage) == 0x20);
}
