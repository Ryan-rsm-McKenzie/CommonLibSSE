#pragma once

#include <string_view>

#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/GFxValue.h"
#include "RE/IMenu.h"


namespace RE
{
	class ActorValueMeter;
	class HUDObject;
	class ShoutMeter;
	class UserEventEnabledEvent;
	struct BSRemoteGamepadEvent;


	// menuDepth = 2
	// flags = kAlwaysOpen | kRequiresUpdate | kAllowSaving | kCustomRendering | kAssignCursorToRenderer
	// context = kNone
	class HUDMenu :
		public IMenu,								 // 00
		public BSTEventSink<UserEventEnabledEvent>,	 // 30
		public BSTEventSink<BSRemoteGamepadEvent>	 // 38
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_HUDMenu;
		constexpr static std::string_view MENU_NAME = "HUD Menu";


		virtual ~HUDMenu();	 // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;				   // 01
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;				   // 04
		virtual void			   AdvanceMovie(float a_interval, UInt32 a_currentTime) override;  // 05
		virtual void			   RefreshPlatform() override;									   // 08

		// override (BSTEventSink<UserEventEnabledEvent>)
		virtual BSEventNotifyControl ProcessEvent(const UserEventEnabledEvent* a_event, BSTEventSource<UserEventEnabledEvent>* a_eventSource) override;	 // 01

		// override (BSTEventSink<BSRemoteGamepadEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSRemoteGamepadEvent* a_event, BSTEventSource<BSRemoteGamepadEvent>* a_eventSource) override;  // 01


		// members
		BSTArray<HUDObject*> objects;  // 40
		ActorValueMeter*	 health;   // 58
		ActorValueMeter*	 stamina;  // 60
		ActorValueMeter*	 magicka;  // 68
		ShoutMeter*			 shout;	   // 70
		GFxValue			 root;	   // 78 - kDisplayObject - "_level0.HUDMovieBaseInstance"
		UInt64				 unk90;	   // 90
	};
	STATIC_ASSERT(sizeof(HUDMenu) == 0x98);
}
