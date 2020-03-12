#pragma once

#include <string_view>

#include "RE/BSTEvent.h"
#include "RE/IMenu.h"
#include "RE/Journal_QuestsTab.h"
#include "RE/Journal_StatsTab.h"
#include "RE/Journal_SystemTab.h"
#include "RE/MenuEventHandler.h"


namespace RE
{
	class BSSystemEvent;


	// menuDepth = 5
	// flags = kPausesGame | kUsesMenuContext | kFreezeFrameBackground | kRequiresUpdate | kTopmostRenderedMenu | kUpdateUsesCursor | kAllowSaving
	// kDisablePauseMenu if game load prevented
	// context = kJournal
	class JournalMenu :
		public IMenu,						// 00
		public MenuEventHandler,			// 30
		public BSTEventSink<BSSystemEvent>	// 40
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_JournalMenu;
		constexpr static std::string_view MENU_NAME = "Journal Menu";


		virtual ~JournalMenu();	 // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;				   // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;				   // 04
		virtual void			   AdvanceMovie(float a_interval, UInt32 a_currentTime) override;  // 05
		virtual void			   PostDisplay() override;										   // 06

		// override (MenuEventHandler)
		virtual bool CanProcess(InputEvent* a_event) override;				// 01
		virtual bool ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03

		// override (BSTEventSink<BSSystemEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSSystemEvent* a_event, BSTEventSource<BSSystemEvent>* a_eventSource) override;	 // 01


		// members
		Journal_QuestsTab questsTab;  // 48
		Journal_StatsTab  statsTab;	  // 80
		Journal_SystemTab systemTab;  // 98
		UInt64			  unkD0;	  // D0
		UInt64			  unkD8;	  // D8
		UInt64			  unkE0;	  // E0
	};
	STATIC_ASSERT(sizeof(JournalMenu) == 0xE8);
}
