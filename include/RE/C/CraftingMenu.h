#pragma once

#include "RE/I/IMenu.h"

namespace RE
{
	namespace CraftingSubMenus
	{
		class CraftingSubMenu;
	}

	// menuDepth = 0
	// flags = kUsesMenuContext | kDisablePauseMenu | kUpdateUsesCursor | kInventoryItemMenu | kDontHideCursorWhenTopmost
	// context = kItemMenu
	class CraftingMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_CraftingMenu;
		constexpr static std::string_view MENU_NAME = "Crafting Menu";

		virtual ~CraftingMenu();  // 00

		// override (IMenu)
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;						  // 04
		virtual void			   AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05
		virtual void			   PostDisplay() override;												  // 06

		// members
		CraftingSubMenus::CraftingSubMenu* subMenu;	 // 30
	};
	static_assert(sizeof(CraftingMenu) == 0x38);
}
