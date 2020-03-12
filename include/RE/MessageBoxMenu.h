#pragma once

#include <string_view>

#include "RE/IMenu.h"


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
		UInt8  unk30;  // 30
		UInt8  pad31;  // 31
		UInt16 pad32;  // 32
		UInt32 pad34;  // 34
	};
	STATIC_ASSERT(sizeof(MessageBoxMenu) == 0x38);
}
