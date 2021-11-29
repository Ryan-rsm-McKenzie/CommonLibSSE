#pragma once

#include "RE/I/IMenu.h"
#include "RE/M/MenuEventHandler.h"

namespace RE
{
	// menuDepth = 13
	// flags = kAllowSaving | kCustomRendering
	// context = kNone
	class CursorMenu :
		public IMenu,            // 00
		public MenuEventHandler  // 30
	{
	public:
		inline static constexpr auto      RTTI = RTTI_CursorMenu;
		constexpr static std::string_view MENU_NAME = "Cursor Menu";

		~CursorMenu() override;  // 00

		// override (IMenu)
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;  // 04

		// override (MenuEventHandler)
		bool CanProcess(InputEvent* a_event) override;              // 01
		bool ProcessThumbstick(ThumbstickEvent* a_event) override;  // 03
		bool ProcessMouseMove(MouseMoveEvent* a_event) override;    // 04
	};
	static_assert(sizeof(CursorMenu) == 0x40);
}
