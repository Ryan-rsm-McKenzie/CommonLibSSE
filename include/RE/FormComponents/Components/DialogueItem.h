#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSString.h"
#include "RE/BSTList.h"
#include "RE/MemoryManager.h"


namespace RE
{
	class Actor;
	class BGSSoundDescriptorForm;
	class ExtraSayToTopicInfo;
	class TESIdleForm;
	class TESQuest;
	class TESTopic;
	class TESTopicInfo;


	class DialogueResponse
	{
	public:
		enum class EmotionType : UInt32
		{
			kNeutral = 0,
			kAnger = 1,
			kDisgust = 2,
			kFear = 3,
			kSad = 4,
			kHappy = 5,
			kSurprise = 6,
			kPuzzled = 7
		};


		// members
		BSString				responseText;  // 00
		EmotionType				emotionType;   // 10
		UInt32					emotionValue;  // 14
		BSFixedString			voice;		   // 18
		TESIdleForm*			speakerIdle;   // 20
		TESIdleForm*			listenerIdle;  // 28
		BGSSoundDescriptorForm* voiceSound;	   // 30
		bool					useEmotion;	   // 38
		bool					soundLip;	   // 39
		UInt16					pad3A;		   // 3A
		UInt32					pad3C;		   // 3C
	};
	STATIC_ASSERT(sizeof(DialogueResponse) == 0x40);


	class DialogueItem : public BSIntrusiveRefCounted
	{
	public:
		DialogueItem(TESQuest* a_quest, TESTopic* a_topic, TESTopicInfo* a_topicInfo, Actor* a_speaker);
		~DialogueItem() = default;

		TES_HEAP_REDEFINE_NEW();


		// members
		UInt32								   pad04;			 // 04
		BSSimpleList<DialogueResponse*>		   responses;		 // 08
		BSSimpleList<DialogueResponse*>::Node* currentResponse;	 // 18
		TESTopicInfo*						   topicInfo;		 // 20
		TESTopic*							   topic;			 // 28
		TESQuest*							   quest;			 // 30
		Actor*								   speaker;			 // 38
		ExtraSayToTopicInfo*				   extraData;		 // 40

	private:
		DialogueItem* Ctor(TESQuest* a_quest, TESTopic* a_topic, TESTopicInfo* a_topicInfo, Actor* a_speaker);
	};
	STATIC_ASSERT(sizeof(DialogueItem) == 0x48);
}
