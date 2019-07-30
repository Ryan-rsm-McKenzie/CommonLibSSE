#include "RE/MenuManager.h"

#include "skse64/GameMenus.h"  // MenuManager

#include "RE/IMenu.h"  // IMenu


namespace RE
{
	MenuManager* MenuManager::GetSingleton()
	{
		using func_t = function_type_t<decltype(&MenuManager::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(&::MenuManager::GetSingleton);
		return func();
	}


	bool MenuManager::IsMenuOpen(const std::string_view& a_menuName)
	{
		auto menu = GetMenu(a_menuName);
		return menu ? menu->IsOpen() : false;
	}


	GPtr<IMenu> MenuManager::GetMenu(const std::string_view& a_menuName)
	{
		auto it = menuTable.find(a_menuName);
		return it != menuTable.end() ? it->second.menuInstance : nullptr;
	}


	GFxMovieView* MenuManager::GetMovieView(const std::string_view& a_menuName)
	{
		auto menu = GetMenu(a_menuName);
		return menu ? menu->view.get() : 0;
	}


	void MenuManager::ShowMenus(bool a_show)
	{
		showMenus = a_show;
	}


	bool MenuManager::IsShowingMenus()
	{
		return showMenus;
	}


	void MenuManager::Register(const std::string_view& a_menuName, CreatorFunc* a_creator)
	{
		menuTable.insert({ a_menuName, { nullptr, a_creator } });
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
