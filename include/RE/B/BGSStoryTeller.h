#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTTuple.h"

namespace RE
{
	class TESQuest;
	struct TESQuestStageItemDoneEvent;

	class BGSStoryTeller :
		public BSTSingletonSDM<BGSStoryTeller>,          // 08
		public BSTEventSink<TESQuestStageItemDoneEvent>  // 00
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSStoryTeller;

		~BGSStoryTeller() override;  // 00

		// override (BSTEventSink<TESQuestStageItemDoneEvent>)
		BSEventNotifyControl ProcessEvent(const TESQuestStageItemDoneEvent* a_event, BSTEventSource<TESQuestStageItemDoneEvent>* a_eventSource) override;  // 01

		static BGSStoryTeller* GetSingleton();

		void BeginShutDownQuest(TESQuest* a_quest);
		void BeginStartUpQuest(TESQuest* a_quest);

		// members
		std::uint8_t                                                                 pad09;                     // 09
		std::uint16_t                                                                pad0A;                     // 0A
		std::uint32_t                                                                pad0C;                     // 0C
		BSTArray<TESQuest*>                                                          queuedStartQuests;         // 10
		BSTArray<TESQuest*>                                                          runningQuests;             // 28
		BSTArray<TESQuest*>                                                          queuedStopQuests;          // 40
		BSTArray<TESQuest*>                                                          infoClearQuests;           // 58
		BSTArray<TESQuest*>                                                          helloTopicQuests;          // 70
		BSTArray<TESQuest*>                                                          greetingTopicQuests;       // 88
		bool                                                                         startUpQuestsInitialized;  // A0
		std::uint8_t                                                                 padA1;                     // A1
		std::uint16_t                                                                padA2;                     // A2
		std::uint32_t                                                                padA4;                     // A4
		BSTHashMap<std::uint32_t, BSTArray<BSTTuple<std::uint32_t, std::uint32_t>>*> questStageWaitMap;         // A8
	};
	static_assert(sizeof(BGSStoryTeller) == 0xD8);
}
