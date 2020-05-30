#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSTEvent.h"
#include "RE/BSTSingleton.h"
#include "RE/GFxValue.h"


namespace RE
{
	class BSSaveDataEvent;
	struct BGSSaveLoadManagerEvent;


	class UISaveLoadManager :
		public BSTSingletonSDM<UISaveLoadManager>,	  // 10
		public BSTEventSink<BSSaveDataEvent>,		  // 00
		public BSTEventSink<BGSSaveLoadManagerEvent>  // 08
	{
	public:
		inline static constexpr auto RTTI = RTTI_UISaveLoadManager;


		virtual ~UISaveLoadManager();  // 00

		// override (BSTEventSink<BSSaveDataEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSSaveDataEvent* a_event, BSTEventSource<BSSaveDataEvent>* a_eventSource) override;	 // 01

		// override (BSTEventSink<BGSSaveLoadManagerEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BGSSaveLoadManagerEvent* a_event, BSTEventSource<BGSSaveLoadManagerEvent>* a_eventSource) override;	 // 01


		// members
		void*		  unk18;  // 18
		UInt64		  unk20;  // 20
		BSFixedString unk28;  // 28
		GFxValue	  unk30;  // 30
		BSFixedString unk48;  // 48
		UInt64		  unk50;  // 50
		UInt64		  unk58;  // 58
		UInt64		  unk60;  // 60
	};
	STATIC_ASSERT(sizeof(UISaveLoadManager) == 0x68);
}
