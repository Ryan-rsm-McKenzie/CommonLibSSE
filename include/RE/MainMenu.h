#pragma once

#include <string_view>

#include "RE/BSTEvent.h"
#include "RE/GFxFunctionHandler.h"
#include "RE/IMenu.h"
#include "RE/ImageData.h"


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
		virtual void			   Accept(CallbackProcessor* a_processor) override;				   // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;				   // 04
		virtual void			   AdvanceMovie(float a_interval, UInt32 a_currentTime) override;  // 05

		// override (BSTEventSink<BSSystemEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSSystemEvent* a_event, BSTEventSource<BSSystemEvent>* a_eventSource) override;	 // 01

		// override (BSTEventSink<BSSaveDataEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSSaveDataEvent* a_event, BSTEventSource<BSSaveDataEvent>* a_eventSource) override;	 // 01

		// override (GFxFunctionHandler)
		virtual void Call(Params& a_params) override;  // 01


		// members
		ImageData unk50;  // 50
		UInt32	  unk68;  // 68
		UInt8	  unk6C;  // 6C
		UInt8	  unk6D;  // 6D
		UInt8	  unk6E;  // 6E
		UInt8	  pad6F;  // 6F
	};
	STATIC_ASSERT(sizeof(MainMenu) == 0x70);
}
