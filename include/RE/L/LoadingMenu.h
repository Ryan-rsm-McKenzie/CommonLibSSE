#pragma once

#include "RE/B/BSTArray.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"

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
		std::uint64_t	unk48;	// 48
		std::uint8_t	unk50;	// 50
		std::uint8_t	unk51;	// 51
		std::uint16_t	pad52;	// 52
		std::uint32_t	pad54;	// 54
		BSTArray<void*> unk58;	// 58
		std::uint32_t	unk70;	// 70
		std::uint32_t	pad74;	// 74
		std::uint64_t	unk78;	// 78
	};
	static_assert(sizeof(LoadingMenu) == 0x80);
}
