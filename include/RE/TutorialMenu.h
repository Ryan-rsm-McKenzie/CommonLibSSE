#pragma once

#include <string_view>

#include "RE/GFxValue.h"
#include "RE/IMenu.h"


namespace RE
{
	// menuDepth = 10
	// flags = kPausesGame | kModal | kUpdateUsesCursor
	// context = kMenuMode
	class TutorialMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_TutorialMenu;
		constexpr static std::string_view MENU_NAME = "Tutorial Menu";


		virtual ~TutorialMenu();  // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04


		// members
		GFxValue root;	// 30 - "Menu_mc"
	};
	STATIC_ASSERT(sizeof(TutorialMenu) == 0x48);
}
