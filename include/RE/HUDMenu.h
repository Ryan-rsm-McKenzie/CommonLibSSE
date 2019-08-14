#pragma once

#include "skse64/GameRTTI.h"  // RTTI_HUDMenu

#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/GFxValue.h"  // GFxValue
#include "RE/IMenu.h"  // IMenu


namespace RE
{
	class ActorValueMeter;
	class HUDObject;
	class ShoutMeter;
	class UserEventEnabledEvent;
	struct BSRemoteGamepadEvent;


	class HUDMenu :
		public IMenu,								// 00
		public BSTEventSink<UserEventEnabledEvent>,	// 30
		public BSTEventSink<BSRemoteGamepadEvent>	// 38
	{
	public:
		inline static const void* RTTI = RTTI_HUDMenu;


		virtual ~HUDMenu();																													// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;																	// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;																		// 04
		virtual void	NextFrame(float a_arg1, UInt32 a_currentTime) override;																// 05
		virtual void	InitMovie() override;																								// 08

		// override (BSTEventSink<UserEventEnabledEvent>)
		virtual	EventResult	ReceiveEvent(UserEventEnabledEvent* a_event, BSTEventSource<UserEventEnabledEvent>* a_eventSource) override;	// 01

		// override (BSTEventSink<BSRemoteGamepadEvent>)
		virtual	EventResult	ReceiveEvent(BSRemoteGamepadEvent* a_event, BSTEventSource<BSRemoteGamepadEvent>* a_eventSource) override;		// 01


		// members
		BSTArray<HUDObject*>	objects;	// 40
		ActorValueMeter*		health;		// 58
		ActorValueMeter*		stamina;	// 60
		ActorValueMeter*		magicka;	// 68
		ShoutMeter*				shout;		// 70
		GFxValue				root;		// 78 - kDisplayObject - "_level0.HUDMovieBaseInstance"
		UInt64					unk90;		// 90
	};
	STATIC_ASSERT(sizeof(HUDMenu) == 0x98);
}
