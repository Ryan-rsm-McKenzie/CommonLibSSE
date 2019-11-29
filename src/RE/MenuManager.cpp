#include "RE/MenuManager.h"

#include "RE/IMenu.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	MenuManager* MenuManager::GetSingleton()
	{
		REL::Offset<MenuManager**> singleton(Offset::MenuManager::Singleton);
		return *singleton;
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
