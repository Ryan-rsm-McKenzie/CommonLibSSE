#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTEvent.h"
#include "RE/BSCore/BSTHashMap.h"
#include "RE/BSCore/BSTSingleton.h"
#include "RE/BSCore/BSTTuple.h"


namespace RE
{
	class TESQuest;
	struct TESQuestStageItemDoneEvent;


	class BGSStoryTeller :
		public BSTSingletonSDM<BGSStoryTeller>,			 // 08
		public BSTEventSink<TESQuestStageItemDoneEvent>	 // 00
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSStoryTeller;


		virtual ~BGSStoryTeller();	// 00

		// override (BSTEventSink<TESQuestStageItemDoneEvent>)
		virtual BSEventNotifyControl ProcessEvent(const TESQuestStageItemDoneEvent* a_event, BSTEventSource<TESQuestStageItemDoneEvent>* a_eventSource) override;  // 01

		static BGSStoryTeller* GetSingleton();

		void BeginShutDownQuest(TESQuest* a_quest);
		void BeginStartUpQuest(TESQuest* a_quest);


		// members
		UInt8													pad09;					   // 09
		UInt16													pad0A;					   // 0A
		UInt32													pad0C;					   // 0C
		BSTArray<TESQuest*>										queuedStartQuests;		   // 10
		BSTArray<TESQuest*>										runningQuests;			   // 28
		BSTArray<TESQuest*>										queuedStopQuests;		   // 40
		BSTArray<TESQuest*>										infoClearQuests;		   // 58
		BSTArray<TESQuest*>										helloTopicQuests;		   // 70
		BSTArray<TESQuest*>										greetingTopicQuests;	   // 88
		bool													startUpQuestsInitialized;  // A0
		UInt8													padA1;					   // A1
		UInt16													padA2;					   // A2
		UInt32													padA4;					   // A4
		BSTHashMap<UInt32, BSTArray<BSTTuple<UInt32, UInt32>>*> questStageWaitMap;		   // A8
	};
	STATIC_ASSERT(sizeof(BGSStoryTeller) == 0xD8);
}
