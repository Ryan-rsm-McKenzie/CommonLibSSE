#include "RE/UIMessageQueue.h"

#include "RE/BSFixedString.h"
#include "RE/Offsets.h"
#include "RE/UIMessage.h"
#include "REL/Relocation.h"


namespace RE
{
	UIMessageQueue* UIMessageQueue::GetSingleton()
	{
		REL::Offset<UIMessageQueue**> singleton(Offset::UIMessageQueue::Singleton);
		return *singleton;
	}


	void UIMessageQueue::AddMessage(const BSFixedString& a_menuName, UI_MESSAGE_TYPE a_type, IUIMessageData* a_data)
	{
		using func_t = decltype(&UIMessageQueue::AddMessage);
		REL::Offset<func_t> func(Offset::UIMessageQueue::AddMessage);
		return func(this, a_menuName, a_type, a_data);
	}


	IUIMessageData* UIMessageQueue::CreateUIMessageData(const BSFixedString& a_name)
	{
		using func_t = decltype(&UIMessageQueue::CreateUIMessageData);
		REL::Offset<func_t> func(Offset::UIMessageQueue::CreateUIMessageData);
		return func(this, a_name);
	}


	void UIMessageQueue::ProcessCommands()
	{
		using func_t = decltype(&UIMessageQueue::ProcessCommands);
		REL::Offset<func_t> func(Offset::UIMessageQueue::ProcessCommands);
		return func(this);
	}
}
