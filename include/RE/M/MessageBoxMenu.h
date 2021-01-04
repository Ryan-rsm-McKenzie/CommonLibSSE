#pragma once

#include "RE/I/IMenu.h"

namespace RE
{
	// menuDepth = 10
	// flags = kPausesGame | kAlwaysOpen | kUsesCursor | kModal
	// context = kMenuMode
	class MessageBoxMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_MessageBoxMenu;
		constexpr static std::string_view MENU_NAME = "MessageBoxMenu";

		virtual ~MessageBoxMenu();	// 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04

		// members
		std::uint8_t  unk30;  // 30
		std::uint8_t  pad31;  // 31
		std::uint16_t pad32;  // 32
		std::uint32_t pad34;  // 34
	};
	static_assert(sizeof(MessageBoxMenu) == 0x38);
}
