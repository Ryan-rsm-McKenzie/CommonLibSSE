#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/J/JournalTab.h"

namespace RE
{
	class BSSaveDataEvent;
	struct BGSSaveLoadManagerEvent;
	struct BSGamerProfileEvent;
	struct BSRemoteGamepadEvent;

	class Journal_SystemTab :
		public JournalTab,                             // 00
		public BSTEventSink<BSSaveDataEvent>,          // 18
		public BSTEventSink<BSGamerProfileEvent>,      // 20
		public BSTEventSink<BGSSaveLoadManagerEvent>,  // 28
		public BSTEventSink<BSRemoteGamepadEvent>      // 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_Journal_SystemTab;

		~Journal_SystemTab() override;  // 00

		// override (JournalTab)
		void Accept(CallbackProcessor* a_cbReg) override;  // 01

		// override (BSTEventSink<BSSaveDataEvent>)
		BSEventNotifyControl ProcessEvent(const BSSaveDataEvent* a_event, BSTEventSource<BSSaveDataEvent>* a_eventSource) override;  // 01

		// override (BSTEventSink<BSGamerProfileEvent>)
		BSEventNotifyControl ProcessEvent(const BSGamerProfileEvent* a_event, BSTEventSource<BSGamerProfileEvent>* a_eventSource) override;  // 01

		// override (BSTEventSink<BGSSaveLoadManagerEvent>)
		BSEventNotifyControl ProcessEvent(const BGSSaveLoadManagerEvent* a_event, BSTEventSource<BGSSaveLoadManagerEvent>* a_eventSource) override;  // 01

		// override (BSTEventSink<BSRemoteGamepadEvent>)
		BSEventNotifyControl ProcessEvent(const BSRemoteGamepadEvent* a_event, BSTEventSource<BSRemoteGamepadEvent>* a_eventSource) override;  // 01
	};
	static_assert(sizeof(Journal_SystemTab) == 0x38);
}
