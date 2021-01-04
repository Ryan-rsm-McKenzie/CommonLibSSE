#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/G/GFxFunctionHandler.h"
#include "RE/I/IMenu.h"
#include "RE/I/ImageData.h"
#include "RE/M/MenuEventHandler.h"

namespace RE
{
	class MenuOpenCloseEvent;

	// menuDepth = 0
	// flags = kUsesMenuContext | kDisablePauseMenu | kUpdateUsesCursor | kInventoryItemMenu | kDontHideCursorWhenTopmost
	// context = kItemMenu
	class CreationClubMenu :
		public IMenu,							 // 00
		public MenuEventHandler,				 // 30
		public GFxFunctionHandler,				 // 40
		public BSTEventSink<MenuOpenCloseEvent>	 // 50
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_CreationClubMenu;
		constexpr static std::string_view MENU_NAME = "Creation Club Menu";

		virtual ~CreationClubMenu();  // 00

		// override (IMenu)
		virtual void AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;	// 05

		// override (MenuEventHandler)
		virtual bool CanProcess(InputEvent* a_event) override;				// 01
		virtual bool ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03

		// override (GFxFunctionHandler)
		virtual void Call(Params& a_params) override;  // 01

		// override (BSTEventSink<MenuOpenCloseEvent>)
		virtual BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;  // 01

		// members
		ImageData background;  // 58
		ImageData details;	   // 70
	};
	static_assert(sizeof(CreationClubMenu) == 0x88);
}
