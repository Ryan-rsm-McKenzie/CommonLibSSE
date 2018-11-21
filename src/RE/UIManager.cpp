#include "RE/UIManager.h"


namespace RE
{
	UIManager* UIManager::GetSingleton()
	{
		typedef UIManager* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::UIManager::GetSingleton));
		return _GetSingleton();
	}


	void UIManager::AddMessage(BSFixedString& a_menuName, UInt32 a_msgID, IUIMessageData* a_pData)
	{
		typedef void _AddMessage_t(UIManager* a_this, BSFixedString& a_menuName, UInt32 a_msgID, IUIMessageData* a_pData);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::UIManager*>(this)->_AddMessage_GetPtr());
		static _AddMessage_t* _AddMessage = reinterpret_cast<_AddMessage_t*>(*ptr);
		_AddMessage(this, a_menuName, a_msgID, a_pData);
	}


	IUIMessageData* UIManager::CreateUIMessageData(const BSFixedString& a_name)
	{
		typedef IUIMessageData* _CreateUIMessageData_t(UIManager* a_this, const BSFixedString& a_name);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::UIManager*>(this)->_CreateUIMessageData_GetPtr());
		static _CreateUIMessageData_t* _CreateUIMessageData = reinterpret_cast<_CreateUIMessageData_t*>(*ptr);
		return _CreateUIMessageData(this, a_name);
	}


	void UIManager::ProcessCommands()
	{
		typedef void _ProcessCommands_t(UIManager* a_this);
		static _ProcessCommands_t* _ProcessCommands = reinterpret_cast<_ProcessCommands_t*>(GetFnAddr(&::UIManager::ProcessCommands));
		_ProcessCommands(this);
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
