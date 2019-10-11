#pragma once

#include "skse64/GameRTTI.h"  // RTTI_Journal_SystemTab

#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/JournalTab.h"  // JournalTab


namespace RE
{
	class BSSaveDataEvent;
	struct BGSSaveLoadManagerEvent;
	struct BSGamerProfileEvent;
	struct BSRemoteGamepadEvent;


	class Journal_SystemTab :
		public JournalTab,								// 00
		public BSTEventSink<BSSaveDataEvent>,			// 18
		public BSTEventSink<BSGamerProfileEvent>,		// 20
		public BSTEventSink<BGSSaveLoadManagerEvent>,	// 28
		public BSTEventSink<BSRemoteGamepadEvent>		// 30
	{
	public:
		inline static const void* RTTI = RTTI_Journal_SystemTab;


		virtual ~Journal_SystemTab();																											// 00

		// override (JournalTab)
		virtual void Accept(CallbackProcessor* a_cbReg) override;																				// 01

		// override (BSTEventSink<BSSaveDataEvent>)
		virtual	EventResult	ReceiveEvent(BSSaveDataEvent* a_event, BSTEventSource<BSSaveDataEvent>* a_eventSource) override;					// 01

		// override (BSTEventSink<BSGamerProfileEvent>)
		virtual	EventResult	ReceiveEvent(BSGamerProfileEvent* a_event, BSTEventSource<BSGamerProfileEvent>* a_eventSource) override;			// 01

		// override (BSTEventSink<BGSSaveLoadManagerEvent>)
		virtual	EventResult	ReceiveEvent(BGSSaveLoadManagerEvent* a_event, BSTEventSource<BGSSaveLoadManagerEvent>* a_eventSource) override;	// 01

		// override (BSTEventSink<BSRemoteGamepadEvent>)
		virtual	EventResult	ReceiveEvent(BSRemoteGamepadEvent* a_event, BSTEventSource<BSRemoteGamepadEvent>* a_eventSource) override;			// 01
	};
	STATIC_ASSERT(sizeof(Journal_SystemTab) == 0x38);
}
