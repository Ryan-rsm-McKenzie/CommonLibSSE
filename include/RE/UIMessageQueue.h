#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTMessageQueue.h"
#include "RE/BSTSingleton.h"
#include "RE/UIMessage.h"


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

		void			AddMessage(const BSFixedString& a_menuName, UI_MESSAGE_TYPE a_type, IUIMessageData* a_data);
		IUIMessageData* CreateUIMessageData(const BSFixedString& a_name);  // uses unk348, but doesn't seem to work like the skse thinks it does
		void			ProcessCommands();


		// members
		UInt8										 pad001;				  // 001
		UInt16										 pad002;				  // 002
		UInt32										 pad004;				  // 004
		BSTCommonStaticMessageQueue<UIMessage*, 100> messages;				  // 008
		BSTHashMap<UnkKey, UnkValue>				 unk348;				  // 348
		UInt32										 poolUsed;				  // 378
		UInt32										 pad37C;				  // 37C
		UIMessage									 messagePool[kPoolSize];  // 380
	};
	STATIC_ASSERT(sizeof(UIMessageQueue) == 0xB80);
}
