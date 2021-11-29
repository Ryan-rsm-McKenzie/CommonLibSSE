#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class IUIMessageData;

	enum class UI_MESSAGE_TYPE
	{
		kUpdate = 0,
		kShow = 1,
		kReshow = 2,
		kHide = 3,
		kForceHide = 4,

		kScaleformEvent = 6,   // BSUIScaleformData
		kUserEvent = 7,        // BSUIMessageData
		kInventoryUpdate = 8,  // InventoryUpdateData
		kUserProfileChange = 9,
		kMUStatusChange = 10,
		kResumeCaching = 11,
		kUpdateController = 12,
		kChatterEvent = 13
	};

	class UIMessage
	{
	public:
		BSFixedString                                    menu;      // 00
		stl::enumeration<UI_MESSAGE_TYPE, std::uint32_t> type;      // 08
		std::uint32_t                                    pad0C;     // 0C
		IUIMessageData*                                  data;      // 10
		bool                                             isPooled;  // 18
		std::uint8_t                                     pad19;     // 19
		std::uint16_t                                    pad1A;     // 1A
		std::uint32_t                                    pad1C;     // 1C
	};
	static_assert(sizeof(UIMessage) == 0x20);
}
