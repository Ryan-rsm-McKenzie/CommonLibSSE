#include "RE/UIManager.h"

#include "RE/BSFixedString.h"
#include "RE/Offsets.h"
#include "RE/UIMessage.h"
#include "REL/Relocation.h"


namespace RE
{
	UIManager* UIManager::GetSingleton()
	{
		REL::Offset<UIManager**> singleton(Offset::UIManager::Singleton);
		return *singleton;
	}


	void UIManager::AddMessage(const BSFixedString& a_menuName, UIMessage::Message a_msgID, IUIMessageData* a_data)
	{
		using func_t = function_type_t<decltype(&UIManager::AddMessage)>;
		REL::Offset<func_t*> func(Offset::UIManager::AddMessage);
		return func(this, a_menuName, a_msgID, a_data);
	}


	IUIMessageData* UIManager::CreateUIMessageData(const BSFixedString& a_name)
	{
		using func_t = function_type_t<decltype(&UIManager::CreateUIMessageData)>;
		REL::Offset<func_t*> func(Offset::UIManager::CreateUIMessageData);
		return func(this, a_name);
	}


	void UIManager::ProcessCommands()
	{
		using func_t = function_type_t<decltype(&UIManager::ProcessCommands)>;
		REL::Offset<func_t*> func(Offset::UIManager::ProcessCommands);
		return func(this);
	}
}
