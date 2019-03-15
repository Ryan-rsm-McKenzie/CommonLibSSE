#pragma once

#include "skse64/Hooks_UI.h"  // UIDelegate_v1
#include "skse64/PapyrusUI.h"  // UIDelegate

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTMessageQueue.h"  // BSTCommonStaticMessageQueue
#include "RE/UIMessage.h"  // UIMessage


namespace RE
{
	class IUIMessageData;


	class UIManager
	{
	public:
		typedef BSTCommonStaticMessageQueue<UIMessage*, 100> MessageQueue;


		enum
		{
			kPoolSize = 0x40,
		};


		static UIManager*	GetSingleton();
		void				AddMessage(const BSFixedString& a_menuName, UIMessage::Message a_msgID, IUIMessageData* a_data);
		IUIMessageData*		CreateUIMessageData(const BSFixedString& a_name);
		void				ProcessCommands();
		void				QueueCommand(UIDelegate* a_cmd);
		void				QueueCommand(UIDelegate_v1* a_cmd);


		// members
		void*			unk000;					// 000 - singleton?
		MessageQueue	messages;				// 008
		UInt8			pad348[0x378 - 0x348];	// 348
		UInt32			poolUsed;				// 378
		UInt32			pad37C;					// 37C
		UIMessage		messagePool[kPoolSize];	// 380
	};
	STATIC_ASSERT(offsetof(UIManager, pad348) == 0x348);
	STATIC_ASSERT(sizeof(UIManager) == 0xB80);
}
