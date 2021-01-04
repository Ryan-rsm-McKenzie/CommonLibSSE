#pragma once

#include "RE/I/IMenu.h"

namespace RE
{
	// menuDepth = 4
	// flags = kNone
	// context = kNone
	class TitleSequenceMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_TitleSequenceMenu;
		constexpr static std::string_view MENU_NAME = "TitleSequence Menu";

		virtual ~TitleSequenceMenu();  // 00

		// override (IMenu)
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;  // 04
	};
	static_assert(sizeof(TitleSequenceMenu) == 0x30);
}
