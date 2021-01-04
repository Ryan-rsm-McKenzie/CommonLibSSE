#pragma once

#include "RE/G/GFxFunctionHandler.h"
#include "RE/I/IMenu.h"

namespace RE
{
	// menuDepth = 10
	// flags = kPausesGame
	// context = kMenuMode
	class CreditsMenu :
		public IMenu,			   // 00
		public GFxFunctionHandler  // 30
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_CreditsMenu;
		constexpr static std::string_view MENU_NAME = "Credits Menu";

		virtual ~CreditsMenu();	 // 00

		// override (IMenu)
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;  // 04

		// override (GFxFunctionHandler)
		virtual void Call(Params& a_params) override;  // 01
	};
	static_assert(sizeof(CreditsMenu) == 0x40);
}
