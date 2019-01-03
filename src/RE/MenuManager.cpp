#include "RE/MenuManager.h"

#include "skse64/GameMenus.h"  // MenuManager

#include "RE/IMenu.h"  // IMenu


namespace RE
{
	MenuManager* MenuManager::GetSingleton(void)
	{
		typedef MenuManager* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::MenuManager::GetSingleton));
		return _GetSingleton();
	}


	bool MenuManager::IsMenuOpen(BSFixedString& a_menuName)
	{
		typedef bool _IsMenuOpen_t(MenuManager* a_this, BSFixedString& a_menuName);
		_IsMenuOpen_t* _IsMenuOpen = reinterpret_cast<_IsMenuOpen_t*>(GetFnAddr(&::MenuManager::IsMenuOpen));
		return _IsMenuOpen(this, a_menuName);
	}


	IMenu* MenuManager::GetMenu(BSFixedString& a_menuName)
	{
		if (!a_menuName.c_str()) {
			return 0;
		}

		auto& it = menuTable.find(a_menuName);
		return (it != menuTable.end()) ? it->GetValue().menuInstance : 0;
	}


	GFxMovieView* MenuManager::GetMovieView(BSFixedString& a_menuName)
	{
		IMenu* menu = GetMenu(a_menuName);
		return menu ? menu->view : 0;
	}


	void MenuManager::ShowMenus(bool a_show)
	{
		showMenus = a_show;
	}


	bool MenuManager::IsShowingMenus()
	{
		return showMenus;
	}


	void MenuManager::Register(const char* a_name, CreatorFunc a_creator)
	{
		typedef void _Register_t(MenuManager* a_this, const char* a_name, CreatorFunc a_creator);
		_Register_t* _Register = reinterpret_cast<_Register_t*>(GetFnAddr(&::MenuManager::Register));
		_Register(this, a_name, a_creator);
	}


	BSTEventSource<MenuOpenCloseEvent>* MenuManager::GetMenuOpenCloseEventSource()
	{
		return static_cast<BSTEventSource<MenuOpenCloseEvent>*>(this);
	}


	BSTEventSource<MenuModeChangeEvent>* MenuManager::GetMenuModeChangeEventSource()
	{
		return static_cast<BSTEventSource<MenuModeChangeEvent>*>(this);
	}


	bool MenuManager::GameIsPaused()
	{
		return numPauseGame > 0;
	}


	bool MenuManager::CrosshairIsPaused()
	{
		return numStopCrosshairUpdate > 0;
	}
}
