#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/G/GFxFunctionHandler.h"
#include "RE/I/IMenu.h"
#include "RE/I/ImageData.h"

namespace RE
{
	class BSSaveDataEvent;
	class BSSystemEvent;

	// menuDepth = 0
	// flags = kPausesGame | kDisablePauseMenu | kRequiresUpdate | kUpdateUsesCursor | kApplicationMenu
	// context = kMenuMode
	class MainMenu :
		public IMenu,						   // 00
		public BSTEventSink<BSSystemEvent>,	   // 30
		public BSTEventSink<BSSaveDataEvent>,  // 38
		public GFxFunctionHandler			   // 40
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_MainMenu;
		constexpr static std::string_view MENU_NAME = "Main Menu";

		virtual ~MainMenu();  // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;						  // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;						  // 04
		virtual void			   AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05

		// override (BSTEventSink<BSSystemEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSSystemEvent* a_event, BSTEventSource<BSSystemEvent>* a_eventSource) override;	 // 01

		// override (BSTEventSink<BSSaveDataEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSSaveDataEvent* a_event, BSTEventSource<BSSaveDataEvent>* a_eventSource) override;	 // 01

		// override (GFxFunctionHandler)
		virtual void Call(Params& a_params) override;  // 01

		// members
		ImageData	  unk50;  // 50
		std::uint32_t unk68;  // 68
		std::uint8_t  unk6C;  // 6C
		std::uint8_t  unk6D;  // 6D
		std::uint8_t  unk6E;  // 6E
		std::uint8_t  pad6F;  // 6F
	};
	static_assert(sizeof(MainMenu) == 0x70);
}
