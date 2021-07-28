#include "RE/U/UIMessageQueue.h"

#include "RE/B/BSFixedString.h"
#include "RE/U/UIMessage.h"

namespace RE
{
	UIMessageQueue* UIMessageQueue::GetSingleton()
	{
		REL::Relocation<UIMessageQueue**> singleton{ Offset::UIMessageQueue::Singleton };
		return *singleton;
	}

	void UIMessageQueue::AddMessage(const BSFixedString& a_menuName, UI_MESSAGE_TYPE a_type, IUIMessageData* a_data)
	{
		using func_t = decltype(&UIMessageQueue::AddMessage);
		REL::Relocation<func_t> func{ Offset::UIMessageQueue::AddMessage };
		return func(this, a_menuName, a_type, a_data);
	}

	IUIMessageData* UIMessageQueue::CreateUIMessageData(const BSFixedString& a_name)
	{
		using func_t = decltype(&UIMessageQueue::CreateUIMessageData);
		REL::Relocation<func_t> func{ Offset::UIMessageQueue::CreateUIMessageData };
		return func(this, a_name);
	}

	void UIMessageQueue::ProcessCommands()
	{
		using func_t = decltype(&UIMessageQueue::ProcessCommands);
		REL::Relocation<func_t> func{ Offset::UIMessageQueue::ProcessCommands };
		return func(this);
	}
}
