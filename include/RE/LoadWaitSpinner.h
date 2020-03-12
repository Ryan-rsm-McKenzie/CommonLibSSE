#pragma once

#include <string_view>

#include "RE/BSTEvent.h"
#include "RE/GFxValue.h"
#include "RE/IMenu.h"


namespace RE
{
	class BSSystemEvent;
	struct BGSSaveLoadManagerEvent;
	struct BSGamerProfileEvent;


	// menuDepth = 10
	// flags = kAlwaysOpen | kAllowSaving
	// context = kNone
	class LoadWaitSpinner :
		public IMenu,								  // 00
		public BSTEventSink<BSSystemEvent>,			  // 30
		public BSTEventSink<BSGamerProfileEvent>,	  // 38
		public BSTEventSink<BGSSaveLoadManagerEvent>  // 40
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_LoadWaitSpinner;
		constexpr static std::string_view MENU_NAME = "LoadWaitSpinner";


		virtual ~LoadWaitSpinner();	 // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01 - { return; }
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04

		// override (BSTEventSink<BSSystemEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSSystemEvent* a_event, BSTEventSource<BSSystemEvent>* a_eventSource) override;	 // 01

		// override (BSTEventSink<BSGamerProfileEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSGamerProfileEvent* a_event, BSTEventSource<BSGamerProfileEvent>* a_eventSource) override;	 // 01

		// override (BSTEventSink<BGSSaveLoadManagerEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BGSSaveLoadManagerEvent* a_event, BSTEventSource<BGSSaveLoadManagerEvent>* a_eventSource) override;	 // 01


		// members
		GFxValue		root;	 // 48 - "Menu_mc"
		volatile SInt32 unk60;	 // 60
		bool			fadeIn;	 // 64
		UInt8			pad65;	 // 65
		UInt16			pad66;	 // 66
	};
	STATIC_ASSERT(sizeof(LoadWaitSpinner) == 0x68);
}
