#pragma once

#include <string_view>

#include "RE/IMenu.h"


namespace RE
{
	// menuDepth = 3
	// flags = kAlwaysOpen | kAllowSaving | kCustomRendering
	// context = kNone
	class FaderMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_FaderMenu;
		constexpr static std::string_view MENU_NAME = "Fader Menu";


		virtual ~FaderMenu();  // 00

		// override (IMenu)
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;  // 04


		// members
		void*  unk30;  // 30 - smart ptr
		UInt8  unk38;  // 38
		UInt8  unk39;  // 39
		UInt16 pad3A;  // 3A
		UInt32 pad3C;  // 3C
	};
	STATIC_ASSERT(sizeof(FaderMenu) == 0x40);
}
