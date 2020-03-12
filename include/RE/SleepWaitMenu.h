#pragma once

#include <string_view>

#include "RE/GFxValue.h"
#include "RE/IMenu.h"


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
		UInt32	 unk30;	 // 30
		UInt32	 pad34;	 // 34
		GFxValue root;	 // 38 - "SleepWaitMenu_mc"
		UInt8	 unk50;	 // 50
		UInt8	 unk51;	 // 51
		UInt16	 pad52;	 // 52
		UInt32	 pad54;	 // 54
	};
	STATIC_ASSERT(sizeof(SleepWaitMenu) == 0x58);
}
