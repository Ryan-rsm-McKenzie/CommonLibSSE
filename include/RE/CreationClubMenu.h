#pragma once

#include <string_view>

#include "RE/BSTEvent.h"
#include "RE/GFxFunctionHandler.h"
#include "RE/IMenu.h"
#include "RE/ImageData.h"
#include "RE/MenuEventHandler.h"


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
		virtual void AdvanceMovie(float a_interval, UInt32 a_currentTime) override;	 // 05

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
	STATIC_ASSERT(sizeof(CreationClubMenu) == 0x88);
}
