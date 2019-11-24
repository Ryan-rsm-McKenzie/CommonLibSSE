#include "RE/UIManager.h"

#include "skse64/GameMenus.h"  // UIManager

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/UIMessage.h"  // UIMessage
#include "REL/Relocation.h"


namespace RE
{
	UIManager* UIManager::GetSingleton()
	{
		using func_t = function_type_t<decltype(&UIManager::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(&::UIManager::GetSingleton);
		return func();
	}


	void UIManager::AddMessage(const BSFixedString& a_menuName, UIMessage::Message a_msgID, IUIMessageData* a_data)
	{
		using func_t = function_type_t<decltype(&UIManager::AddMessage)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::UIManager, AddMessage, func_t*);
		return func(this, a_menuName, a_msgID, a_data);
	}


	IUIMessageData* UIManager::CreateUIMessageData(const BSFixedString& a_name)
	{
		using func_t = function_type_t<decltype(&UIManager::CreateUIMessageData)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::UIManager, CreateUIMessageData, func_t*);
		return func(this, a_name);
	}


	void UIManager::ProcessCommands()
	{
		using func_t = function_type_t<decltype(&UIManager::ProcessCommands)>;
		func_t* func = unrestricted_cast<func_t*>(&::UIManager::ProcessCommands);
		return func(this);
	}


	void UIManager::QueueCommand(UIDelegate* a_cmd)
	{
		reinterpret_cast<::UIManager*>(this)->QueueCommand(a_cmd);
	}


	void UIManager::QueueCommand(UIDelegate_v1* a_cmd)
	{
		reinterpret_cast<::UIManager*>(this)->QueueCommand(a_cmd);
	}
}
