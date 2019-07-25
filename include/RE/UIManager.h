#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/BSTMessageQueue.h"  // BSTCommonStaticMessageQueue
#include "RE/BSTSingleton.h"  // BSTSingletonSDM
#include "RE/UIMessage.h"  // UIMessage


class UIDelegate;
class UIDelegate_v1;


namespace RE
{
	class IUIMessageData;


	class UIManager : public BSTSingletonSDM<UIManager>
	{
	public:
		enum { kPoolSize = 0x40 };


		static UIManager* GetSingleton();

		void			AddMessage(const BSFixedString& a_menuName, UIMessage::Message a_msgID, IUIMessageData* a_data);
		IUIMessageData*	CreateUIMessageData(const BSFixedString& a_name);
		void			ProcessCommands();
		void			QueueCommand(UIDelegate* a_cmd);
		void			QueueCommand(UIDelegate_v1* a_cmd);


		// members
		BSTCommonStaticMessageQueue<UIMessage*, 100>	messages;				// 008
		BSTHashMap<UnkKey, UnkValue>					unk348;					// 348
		UInt32											poolUsed;				// 378
		UInt32											pad37C;					// 37C
		UIMessage										messagePool[kPoolSize];	// 380
	};
	STATIC_ASSERT(sizeof(UIManager) == 0xB80);
}
