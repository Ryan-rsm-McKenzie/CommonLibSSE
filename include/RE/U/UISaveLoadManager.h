#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/G/GFxValue.h"

namespace RE
{
	class BSSaveDataEvent;
	struct BGSSaveLoadManagerEvent;

	class UISaveLoadManager :
		public BSTSingletonSDM<UISaveLoadManager>,    // 10
		public BSTEventSink<BSSaveDataEvent>,         // 00
		public BSTEventSink<BGSSaveLoadManagerEvent>  // 08
	{
	public:
		inline static constexpr auto RTTI = RTTI_UISaveLoadManager;

		~UISaveLoadManager() override;  // 00

		// override (BSTEventSink<BSSaveDataEvent>)
		BSEventNotifyControl ProcessEvent(const BSSaveDataEvent* a_event, BSTEventSource<BSSaveDataEvent>* a_eventSource) override;  // 01

		// override (BSTEventSink<BGSSaveLoadManagerEvent>)
		BSEventNotifyControl ProcessEvent(const BGSSaveLoadManagerEvent* a_event, BSTEventSource<BGSSaveLoadManagerEvent>* a_eventSource) override;  // 01

		// members
		void*         unk18;  // 18
		std::uint64_t unk20;  // 20
		BSFixedString unk28;  // 28
		GFxValue      unk30;  // 30
		BSFixedString unk48;  // 48
		std::uint64_t unk50;  // 50
		std::uint64_t unk58;  // 58
		std::uint64_t unk60;  // 60
	};
	static_assert(sizeof(UISaveLoadManager) == 0x68);
}
