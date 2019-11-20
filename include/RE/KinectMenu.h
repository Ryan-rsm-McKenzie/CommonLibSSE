#pragma once

#include "skse64/GameRTTI.h"  // RTTI_KinectMenu

#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/GFxValue.h"  // GFxValue
#include "RE/IMenu.h"  // IMenu


namespace RE
{
	class MenuOpenCloseEvent;


	class KinectMenu :
		public IMenu,							// 00
		public BSTEventSink<MenuOpenCloseEvent>	// 30
	{
	public:
		inline static const void* RTTI = RTTI_KinectMenu;


		virtual ~KinectMenu();																										// 00

		// override (IMenu)
		virtual Result	ProcessMessage(UIMessage* a_message) override;																// 04

		// override (BSTEventSink<MenuOpenCloseEvent>)
		virtual	EventResult	ReceiveEvent(MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;	// 01


		// members
		GFxValue root;	// 38 - "Menu_mc"
	};
	STATIC_ASSERT(sizeof(KinectMenu) == 0x50);
}
