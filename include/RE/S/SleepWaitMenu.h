#pragma once

#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"

namespace RE
{
	// menuDepth = 4
	// flags = kPausesGame | kRequiresUpdate | kAllowSaving | kApplicationMenu
	// kUsesCursor if gamepad disabled
	// context = kMenuMode
	class SleepWaitMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_SleepWaitMenu;
		constexpr static std::string_view MENU_NAME = "Sleep/Wait Menu";

		virtual ~SleepWaitMenu();  // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04

		// members
		std::uint32_t unk30;  // 30
		std::uint32_t pad34;  // 34
		GFxValue	  root;	  // 38 - "SleepWaitMenu_mc"
		std::uint8_t  unk50;  // 50
		std::uint8_t  unk51;  // 51
		std::uint16_t pad52;  // 52
		std::uint32_t pad54;  // 54
	};
	static_assert(sizeof(SleepWaitMenu) == 0x58);
}
