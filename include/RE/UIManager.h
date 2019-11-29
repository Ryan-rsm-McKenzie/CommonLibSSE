#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTMessageQueue.h"
#include "RE/BSTSingleton.h"
#include "RE/UIMessage.h"


namespace RE
{
	class IUIMessageData;


	class UIManager : public BSTSingletonSDM<UIManager>
	{
	public:
		enum { kPoolSize = 0x40 };


		static UIManager* GetSingleton();

		void			AddMessage(const BSFixedString& a_menuName, UIMessage::Message a_msgID, IUIMessageData* a_data);
		IUIMessageData*	CreateUIMessageData(const BSFixedString& a_name);	// uses unk348, but doesn't seem to work like the skse thinks it does
		void			ProcessCommands();


		// members
		BSTCommonStaticMessageQueue<UIMessage*, 100>	messages;				// 008
		BSTHashMap<UnkKey, UnkValue>					unk348;					// 348
		UInt32											poolUsed;				// 378
		UInt32											pad37C;					// 37C
		UIMessage										messagePool[kPoolSize];	// 380
	};
	STATIC_ASSERT(sizeof(UIManager) == 0xB80);
}
