#include "RE/MenuManager.h"

#include "skse64/GameMenus.h"  // MenuManager

#include "RE/IMenu.h"  // IMenu


namespace RE
{
	MenuManager* MenuManager::GetSingleton()
	{
		using func_t = function_type_t<decltype(&MenuManager::GetSingleton)>;
		func_t* func = function_cast<func_t*>(&::MenuManager::GetSingleton);
		return func();
	}


	bool MenuManager::IsMenuOpen(BSFixedString& a_menuName)
	{
		using func_t = function_type_t<decltype(&MenuManager::IsMenuOpen)>;
		func_t* func = function_cast<func_t*>(&::MenuManager::IsMenuOpen);
		return func(this, a_menuName);
	}


	IMenu* MenuManager::GetMenu(BSFixedString& a_menuName)
	{
		if (!a_menuName.c_str()) {
			return 0;
		}

		auto it = menuTable.find(a_menuName);
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
		using func_t = function_type_t<decltype(&MenuManager::Register)>;
		func_t* func = function_cast<func_t*>(&::MenuManager::Register);
		return func(this, a_name, a_creator);
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
