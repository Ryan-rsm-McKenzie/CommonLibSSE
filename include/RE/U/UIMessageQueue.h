#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTMessageQueue.h"
#include "RE/B/BSTSingleton.h"
#include "RE/U/UIMessage.h"

namespace RE
{
	class IUIMessageData;
	class UIMessage;

	class UIMessageQueue : public BSTSingletonSDM<UIMessageQueue>
	{
	public:
		enum
		{
			kPoolSize = 64
		};

		static UIMessageQueue* GetSingleton();

		void            AddMessage(const BSFixedString& a_menuName, UI_MESSAGE_TYPE a_type, IUIMessageData* a_data);
		IUIMessageData* CreateUIMessageData(const BSFixedString& a_name);  // uses unk348, but doesn't seem to work like the skse thinks it does
		void            ProcessCommands();

		// members
		std::uint8_t                                 pad001;                  // 001
		std::uint16_t                                pad002;                  // 002
		std::uint32_t                                pad004;                  // 004
		BSTCommonStaticMessageQueue<UIMessage*, 100> messages;                // 008
		BSTHashMap<UnkKey, UnkValue>                 unk348;                  // 348
		std::uint32_t                                poolUsed;                // 378
		std::uint32_t                                pad37C;                  // 37C
		UIMessage                                    messagePool[kPoolSize];  // 380
	};
	static_assert(sizeof(UIMessageQueue) == 0xB80);
}
