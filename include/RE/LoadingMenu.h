#pragma once

#include <string_view>

#include "RE/BSTArray.h"
#include "RE/GFxValue.h"
#include "RE/IMenu.h"


namespace RE
{
	// menuDepth = 9
	// flags = kPausesGame | kAlwaysOpen | kAllowSaving | kApplicationMenu
	// context = kNone
	class LoadingMenu : public IMenu
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_LoadingMenu;
		constexpr static std::string_view MENU_NAME = "Loading Menu";


		virtual ~LoadingMenu();	 // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04


		// members
		GFxValue		root;	// 30 - "Menu_mc"
		UInt64			unk48;	// 48
		UInt8			unk50;	// 50
		UInt8			unk51;	// 51
		UInt16			pad52;	// 52
		UInt32			pad54;	// 54
		BSTArray<void*> unk58;	// 58
		UInt32			unk70;	// 70
		UInt32			pad74;	// 74
		UInt64			unk78;	// 78
	};
	STATIC_ASSERT(sizeof(LoadingMenu) == 0x80);
}
