#include "RE/MenuManager.h"


namespace RE
{
	MenuManager* MenuManager::GetSingleton(void)
	{
		typedef MenuManager* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::MenuManager::GetSingleton));
		return _GetSingleton();
	}


	EventDispatcher<MenuOpenCloseEvent>* MenuManager::MenuOpenCloseEventDispatcher()
	{
		typedef EventDispatcher<MenuOpenCloseEvent>* _MenuOpenCloseEventDispatcher_t(MenuManager* a_this);
		static _MenuOpenCloseEventDispatcher_t* _MenuOpenCloseEventDispatcher = reinterpret_cast<_MenuOpenCloseEventDispatcher_t*>(GetFnAddr(&::MenuManager::MenuOpenCloseEventDispatcher));
		return _MenuOpenCloseEventDispatcher(this);
	}


	bool MenuManager::IsMenuOpen(BSFixedString* a_menuName)
	{
		typedef bool _IsMenuOpen_t(MenuManager* a_this, BSFixedString* a_menuName);
		static _IsMenuOpen_t* _IsMenuOpen = reinterpret_cast<_IsMenuOpen_t*>(GetFnAddr(&::MenuManager::IsMenuOpen));
		return _IsMenuOpen(this, a_menuName);
	}


	IMenu* MenuManager::GetMenu(BSFixedString* a_menuName)
	{
		typedef IMenu* _GetMenu_t(MenuManager* a_this, BSFixedString* a_menuName);
		static _GetMenu_t* _GetMenu = reinterpret_cast<_GetMenu_t*>(GetFnAddr(&::MenuManager::GetMenu));
		return _GetMenu(this, a_menuName);
	}


	GFxMovieView* MenuManager::GetMovieView(BSFixedString* a_menuName)
	{
		typedef GFxMovieView* _GetMovieView_t(MenuManager* a_this, BSFixedString* a_menuName);
		static _GetMovieView_t* _GetMovieView = reinterpret_cast<_GetMovieView_t*>(GetFnAddr(&::MenuManager::GetMovieView));
		return _GetMovieView(this, a_menuName);
	}


	void MenuManager::ShowMenus(bool a_show)
	{
		typedef void _ShowMenus_t(MenuManager* a_this, bool a_show);
		static _ShowMenus_t* _ShowMenus = reinterpret_cast<_ShowMenus_t*>(GetFnAddr(&::MenuManager::ShowMenus));
		_ShowMenus(this, a_show);
	}


	bool MenuManager::IsShowingMenus()
	{
		typedef bool _IsShowingMenus_t(MenuManager* a_this);
		static _IsShowingMenus_t* _IsShowingMenus = reinterpret_cast<_IsShowingMenus_t*>(GetFnAddr(&::MenuManager::IsShowingMenus));
		return _IsShowingMenus(this);
	}


	void MenuManager::Register(const char* a_name, CreatorFunc a_creator)
	{
		typedef void _Register_t(MenuManager* a_this, const char* a_name, CreatorFunc a_creator);
		static _Register_t* _Register = reinterpret_cast<_Register_t*>(GetFnAddr(&::MenuManager::Register));
		_Register(this, a_name, a_creator);
	}


	bool MenuManager::GameIsPaused()
	{
		return numPauseGame > 0;
	}
}
